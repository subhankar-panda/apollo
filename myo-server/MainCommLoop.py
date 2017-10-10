import myo as libmyo
from time import sleep
from myo import Hub, DeviceListener
import serial
libmyo.init('../../downloads/sdk/myo.framework')


ser = serial.Serial('/dev/cu.HC-05-DevB', 9600)


class Listener(DeviceListener):

    def on_pose(self, myo, timestamp, pose):
        if pose == libmyo.Pose.fist:
            ser.write(bytes('F', "utf-8"))
        elif pose == libmyo.Pose.rest:
            ser.write(bytes('S', "utf-8"))
        elif pose == libmyo.Pose.wave_in:
            ser.write(bytes('L', "utf-8"))
        elif pose == libmyo.Pose.wave_out:
            ser.write(bytes('R', "utf-8"))
        elif pose == libmyo.Pose.double_tap:
            ser.write(bytes('B', "utf-8"))


hub = Hub()
hub.run(1000, Listener())
try:
    while True:
        sleep(0.5)
except KeyboardInterrupt:
    print('\nQuit')
finally:
    hub.shutdown()

