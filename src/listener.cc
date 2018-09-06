/*
 * Copyright (C) 2012 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include <ignition/math/Pose3.hh>

#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/gazebo_client.hh>
#include <gazebo/msgs/gps.pb.h>

#include <iostream>

/////////////////////////////////////////////////
// Function is called everytime a message is received.
void cb(ConstPosePtr &_msg)
{
  // Dump the message contents to stdout.
  //std::cout << _msg.position.x;
  std::cout << _msg->DebugString() << std::endl;
  std::cout << "Hello world!" << std::endl;
  std::cout << _msg->position().x() << std::endl;
  std::cout << _msg->orientation().w() << std::endl;
}

void readGPS(ConstGPSPtr &_msg)
{
  // Dump the message contents to stdout.
  //std::cout << _msg.position.x;
  std::cout << _msg->DebugString() << std::endl;
  std::cout << "Hello world!" << std::endl;
  std::cout << _msg->link_name() << std::endl;
  std::cout << _msg->latitude_deg() << std::endl;
  std::cout << _msg->longitude_deg() << std::endl;
  std::cout << _msg->altitude() << std::endl;
  std::cout << _msg->velocity_east() << std::endl;
  std::cout << _msg->velocity_north() << std::endl;
  std::cout << _msg->velocity_up() << std::endl;
}
/////////////////////////////////////////////////
int main(int _argc, char **_argv)
{
  // Load gazebo
  gazebo::client::setup(_argc, _argv);

  // Create our node for communication
  gazebo::transport::NodePtr node(new gazebo::transport::Node());
  node->Init();

  // Listen to Gazebo world_stats topic
  gazebo::transport::SubscriberPtr sub = node->Subscribe("~/pose_example", &cb);
  gazebo::transport::SubscriberPtr subGPS = node->Subscribe("~/prius_hybrid_123/sensors/gps_sensor", &readGPS);

  // Busy wait loop...replace with your own code as needed.
  while (true)
    gazebo::common::Time::MSleep(10);

  // Make sure to shut everything down.
  gazebo::client::shutdown();
}
