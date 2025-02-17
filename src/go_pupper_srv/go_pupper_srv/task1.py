########
# Name: client_go_pupper
#
# Purpose: Go Pupper Client. Sample client code which will communicate with the GoPupper service by
#          passing along command line arguments form the user. (e.g., move_forward, move_backward, etc)
#
# Usage: First launch the service (see lab/file). Then you can run the client like this:
#        ros2 run go_pupper_srv client move_forward
#
# Author: Prof. Riek <lriek@ucsd.edu>
#
# Acknowledgements: Used some code from ROS 2 Tutorials and MangDang's ROS git repo 
#  https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Writing-A-Simple-Py-Service-And-Client.html
#  https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Custom-ROS2-Interfaces.html#test-the-new-interfaces
#  https://github.com/mangdangroboticsclub/mini_pupper_ros/blob/ros2-dev/mini_pupper_dance/mini_pupper_dance/dance_server.py
#
# Date: 30 Apr 2024
########

# Import the ROS2 interface we wrote, called GoPupper. This specifies the message type.
from pupper_interfaces.srv import GoPupper

# Lets us read arguments from the command line as needed
import sys

# Packages to let us create nodes and spin them up
import rclpy
from rclpy.node import Node
import time
import RPi.GPIO as GPIO
import sounddevice as sd
import soundfile as sf
import random
import pyttsx3


from MangDang.mini_pupper.display import Display, BehaviorState

# There are 4 areas for touch actions
# Each GPIO to each touch area
touchPin_Front = 6
touchPin_Left  = 3
touchPin_Right = 16
touchPin_Back  = 2

# Use GPIO number but not PIN number
GPIO.setmode(GPIO.BCM)

# Set up GPIO numbers to input
GPIO.setup(touchPin_Front, GPIO.IN)
GPIO.setup(touchPin_Left,  GPIO.IN)
GPIO.setup(touchPin_Right, GPIO.IN)
GPIO.setup(touchPin_Back,  GPIO.IN)


###
# Name: Minimal Client Async
#
# Purpose: "The MinimalClientAsync class constructor initializes the node with the name minimal_client_async. "
#          "The constructor definition creates a client with the same type and name as the service node. 
#          The type and name must match for the client and service to be able to communicate."
#
# Prof Riek Notes: You can call this method whatever you like, this is just the modified ROS tutorial code. 
######
class MinimalClientAsync(Node):

    def __init__(self):
        super().__init__('minimal_client_async')
        #super().__init__('client_go_pupper')
        self.cli = self.create_client(GoPupper, 'pup_command')


        # "The while loop in the constructor checks if a service matching the type and name of the client 
        # is available once a second." 
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')

        # "Finally it creates a new request object.""
        self.req = GoPupper.Request()

    ###
    # Name: send_move_request
    # Purpose: send_move_request method, send request and spin until receive response or fail
    # Arguments:  self (reference the current class), move_command (the command we plan to send to the server)
    #####
    def send_move_request(self, move_command):
        self.req = GoPupper.Request()
        self.req.command = move_command
        print("In send_move_request, command is: %s" % self.req.command)
        self.future = self.cli.call_async(self.req)  # send the command to the server
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

###
# Name: Main
# Purpose: "Constructs a MinimalClientAsync object, sends the request using 
#           the passed-in command-line arguments, and logs the results."
#####
def generate_sequence():
    moves = ["move_left", "move_right", "move_forward", "move_backward"]
    random_int = random.choice([0, 1, 2, 3])
    sequence = []
    for i in range(16):
        sequence.append(moves[random_int])
    return sequence

def move_pupper(move):
    minimal_client = MinimalClientAsync()
    
    disp = Display()
    leftEyeLoc = "/home/ubuntu/ros2_ws/img/leftRZ.png"
    frontEyeLoc = "/home/ubuntu/ros2_ws/img/frontRZ.png"
    backEyeLoc = "/home/ubuntu/ros2_ws/img/backwardRZ.png"
    rightEyeLoc = "/home/ubuntu/ros2_ws/img/rightRZ.png"

    leftSound = "/home/ubuntu/ros2_ws/sound/left.wav"
    rightSound = "/home/ubuntu/ros2_ws/sound/right.wav"
    frontSound = "/home/ubuntu/ros2_ws/sound/forward.wav"
    backSound = "/home/ubuntu/ros2_ws/sound/backward.wav"

    if move == 'move_forward':
        disp.show_image(frontEyeLoc)
        data,rate=sf.read(frontSound)
        sd.play(data,rate)
    elif move == 'move_backward':
        disp.show_image(backEyeLoc)
        data,rate=sf.read(backSound)
        sd.play(data,rate)
    elif move == 'move_left':
        disp.show_image(leftEyeLoc)
        data,rate=sf.read(leftSound)
        sd.play(data,rate)
    elif move == 'move_right':
        disp.show_image(rightEyeLoc)
        data,rate=sf.read(rightSound)
        sd.play(data,rate)
    minimal_client.send_move_request(move)
    print(move)


def main(args=None):
    rclpy.init(args=args)
    minimal_client = MinimalClientAsync()

    # Call send move request (which sends cmd to server)
    # minimal_client.send_move_request(cmd)
    disp = Display()
    leftEyeLoc = "/home/ubuntu/ros2_ws/img/leftRZ.png"
    frontEyeLoc = "/home/ubuntu/ros2_ws/img/frontRZ.png"
    backEyeLoc = "/home/ubuntu/ros2_ws/img/backwardRZ.png"
    idleEyeLoc = "/home/ubuntu/ros2_ws/img/idleRZ.png"

    sequence = generate_sequence()
    engine = pyttsx3.init()

    
    text = "follow me for the first four moves."
    engine.say(text)
    engine.runAndWait()
    # show the first 4 moves
    for i in range(0, 4):
        move_pupper(sequence[i])
        time.sleep(0.8)
    
    # show the second 4 moves
    for i in range(4, 8):
        move_pupper(sequence[i])
        time.sleep(0.8)

    # show the first 8 moves
    for i in range(0, 8):
        move_pupper(sequence[i])
        time.sleep(0.8)

    # show the third 4 moves
    for i in range(8, 12):
        move_pupper(sequence[i])
        time.sleep(0.8)

    # show the fourth 4 moves
    for i in range(12, 16):
        move_pupper(sequence[i])
        time.sleep(0.8)
    
    # show the second 8 moves
    for i in range(8, 16):
        move_pupper(sequence[i])
        time.sleep(0.8)

    # show all 16 moves
    for i in range(16):
        move_pupper(sequence[i])
        time.sleep(0.8)

    


   

    # This spins up a client node, checks if it's done, throws an exception of there's an issue
    # (Probably a bit redundant with other code and can be simplified. But right now it works, so ¯\_(ツ)_/¯)
    while rclpy.ok():
        rclpy.spin_once(minimal_client)
        if minimal_client.future.done():
            try:
                response = minimal_client.future.result()
            except Exception as e:
                minimal_client.get_logger().info(
                    'Service call failed %r' % (e,))
            else:
                minimal_client.get_logger().info(
                   'Result of command: %s ' %
                   (response))
            break

    # Destroy node and shut down
    minimal_client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
