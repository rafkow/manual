class Motor:
    motors_number = 0
    motors_object_list = []
    def __init__(self):
        self.__current_step = 0
        self.__direction = 0
        self.__step_precision = 1
        self.__steps_number = 0
        self.__distance = 0
        self.__motor_enable = 0
        Motor.motors_number += 1
        Motor.motors_object_list.append(self)

    def next_step(self):
        self.__current_step += 1

    def get_current_step(self):
        return self.__current_step

    def get_steps_number(self):
        return self.__steps_number

    def set_direction(self,direction):
        if "L" in direction.upper():
            self.__direction = 0
        else:
            self.__direction = 1

    def set_distance(self,distance):
        self.__distance = self.__step_precision * distance * 1

    def motor_enable(self):
        if 0 == self.__motor_enable:
            self.__motor_enable = 1

    def motor_disable(self):
        if 1 == self.__motor_enable:
            self.__motor_enable = 0

    def motor_status(self):
        return self.__motor_enable

    @staticmethod
    def enable_motors():
        for motor in Motor.motors_object_list:
            Motor.motor_enable(motor)

    @staticmethod
    def disable_motors():
        for motor in Motor.motors_object_list:
            Motor.motor_disable(motor)

    def steps_comparison(self,m):
        if self.__steps_number >= Motor.get_steps_number(m):
            return self.__steps_number
        else:
            return Motor.get_steps_number(m)





def maping(x,max_x,max_y):
    return (int)(x*max_y/max_x)

for x in range(1):
    print(x,":",maping(x,34,20))

m = Motor()
print m.get_current_step()
m.next_step()
print m.get_current_step()
m2 = Motor()
print m.motor_status()
print m2.motor_status()
print Motor.motors_number
Motor.enable_motors()
Motor.enable_motors()
print m.get_current_step()
print m.motor_status()
print m2.motor_status()

