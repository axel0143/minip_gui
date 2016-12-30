#include <ros/ros.h>
#include <gtkmm.h>
#include <std_msgs/Int8.h>

using namespace std;
using namespace Gtk;

ros::Publisher chatter_pub;

void on_blueButton_click()
{
	std_msgs::Int8 msg;
	msg.data = 0;
	chatter_pub.publish(msg);
	ROS_INFO("Blue goal sent.");
}

void on_redButton_click()
{
	std_msgs::Int8 msg;
	msg.data = 1;
	chatter_pub.publish(msg);
	ROS_INFO("Red goal sent.");
}

void on_pinkButton_click()
{
	std_msgs::Int8 msg;
	msg.data = 2;
	chatter_pub.publish(msg);
	ROS_INFO("Pink goal sent.");
}	

void on_yellowButton_click()
{
	std_msgs::Int8 msg;
	msg.data = 3;
	chatter_pub.publish(msg);
	ROS_INFO("Yellow goal sent.");
}

int main (int argc, char *argv[])
{
	ros::init(argc, argv, "minip_gui");
	ros::NodeHandle n;
	chatter_pub = n.advertise<std_msgs::Int8>("gui_goal", 1000);
	Main kit(argc, argv);
	Window window;
	window.set_default_size(360,240);
	window.set_title("Miniproject GUI");
	window.set_position(WIN_POS_CENTER);

	Box *vbox = new Box(ORIENTATION_VERTICAL,0);
	window.add(*vbox);
	vbox->show();
	
	Grid *grid = new Grid;
	grid->set_border_width(10);
	vbox->add(*grid);
	grid->show();
	
	Button blueButton("Blue");
	grid->attach(blueButton, 0, 0, 1, 1);
	blueButton.signal_clicked().connect(
	sigc::ptr_fun(&on_blueButton_click)
	);
	blueButton.show();
	
	Button redButton ("Red");
	grid->attach(redButton, 1, 0, 1, 1);
	redButton.signal_clicked().connect(
	sigc::ptr_fun(&on_redButton_click)
	);
	redButton.show();
	
	Button pinkButton ("Pink");
	grid->attach(pinkButton, 0, 1, 1, 1);
	pinkButton.signal_clicked().connect(
	sigc::ptr_fun(&on_pinkButton_click)
	);
	pinkButton.show();
	
	Button yellowButton ("Yellow");
	grid->attach(yellowButton, 1, 1, 2, 1);
	yellowButton.signal_clicked().connect(
	sigc::ptr_fun(&on_yellowButton_click)
	);
	yellowButton.show();
	
	Main::run(window);
	return 0;
}
