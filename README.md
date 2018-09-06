
gazebo node, test for publishing and subscribing

It's difficult for subcribing a message from a topic.

All active topics can be listed by running command "gz topic -l" in terminal.
Use grep to filter the one you want.

The message type can be found by running command "gz topic -i topic name" in terminal.
This type will be useful when defining the callback function of subscription.
if the Type is gazebo.msgs.XXX, the argument of callback function should be "ConstXXXPtr &msg"
if some error occurs, please search the source code installed on your machine. For example, look "/usr/local/include/gazebo-10/gazebo/msg/" for related source file. Include the file in your cpp, and find the correct name from the file. That file contains many infomation about how you could call it's methods and members.

Maybe it's trouble finding the answer always from source file, it's the best way to solve problems absolutely.
