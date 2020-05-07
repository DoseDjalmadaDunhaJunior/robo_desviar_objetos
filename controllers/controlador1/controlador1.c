/*
 * File:          WebotsAula2.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/motor.h>, etc.
 */
#include <webots/robot.h>
#include <webots/distance_sensor.h>
#include <webots/motor.h>
#include <math.h>
#include <stdio.h>

/*
 * You may want to add macros here.
 */
#define TIME_STEP 64

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv) {
  /* necessary to initialize webots stuff */
  wb_robot_init();
  WbDeviceTag E = wb_robot_get_device("left wheel motor");
  WbDeviceTag D = wb_robot_get_device("right wheel motor");
  
  WbDeviceTag s0 = wb_robot_get_device("ps0");  
  WbDeviceTag s1 = wb_robot_get_device("ps1");  
  WbDeviceTag s2 = wb_robot_get_device("ps2");  
  WbDeviceTag s3 = wb_robot_get_device("ps3");  
  WbDeviceTag s4 = wb_robot_get_device("ps4");  
  WbDeviceTag s5 = wb_robot_get_device("ps5");  
  WbDeviceTag s6 = wb_robot_get_device("ps6");  
  WbDeviceTag s7 = wb_robot_get_device("ps7");
  
  wb_distance_sensor_enable(s0,TIME_STEP);
  wb_distance_sensor_enable(s1,TIME_STEP);
  wb_distance_sensor_enable(s2,TIME_STEP);
  wb_distance_sensor_enable(s3,TIME_STEP);
  wb_distance_sensor_enable(s4,TIME_STEP);
  wb_distance_sensor_enable(s5,TIME_STEP);
  wb_distance_sensor_enable(s6,TIME_STEP);
  wb_distance_sensor_enable(s7,TIME_STEP);
  
  wb_motor_set_position(E, INFINITY);
  wb_motor_set_position(D, INFINITY);
  
  double E_speed = 1.0;
  double D_speed = 10.0;
  double s0_value = 0;
  double s1_value = 0;
  double s2_value = 0;
  double s3_value = 0;
  double s4_value = 0;
  double s5_value = 0;
  double s6_value = 0;
  double s7_value = 0;
  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */
  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
  while (wb_robot_step(TIME_STEP) != -1) {
  
  s0_value = wb_distance_sensor_get_value(s0);
  s1_value = wb_distance_sensor_get_value(s1);
  s2_value = wb_distance_sensor_get_value(s2);
  s3_value = wb_distance_sensor_get_value(s3);
  s4_value = wb_distance_sensor_get_value(s4);
  s5_value = wb_distance_sensor_get_value(s5);
  s6_value = wb_distance_sensor_get_value(s6);
  s7_value = wb_distance_sensor_get_value(s7);
  
  printf("oi\n");
  
  wb_motor_set_velocity(E,E_speed);
  wb_motor_set_velocity(D,D_speed);
    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */

    /* Process sensor data here */

    /*
     * Enter here functions to send actuator commands, like:
     * wb_motor_set_position(my_actuator, 10.0);
     */
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}