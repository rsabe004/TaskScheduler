#ifndef __DISPLAY_TEST_HPP__
#define __DISPLAY_TEST_HPP__
#include "../headers/Display.hpp"
#include "../headers/Scheduler.hpp"

TEST(TestingList, CreateListID){
	int id2 = 0;
	int &id=id2;
	List* test = new List(id);
	int ID = test->getID();
	
	EXPECT_EQ(ID,0);
}

TEST(TestingList, SettingName){
	int id2 = 1;
	int &id = id2;

	List* test = new List (id);
	test->setName("My List");
	string listName = test->getName();

	EXPECT_EQ(listName, "My List");
}
TEST(TestingList, EmptyName){
	int id2 = 1;
	int &id = id2;

	List* test = new List(id);
	test->setName("");
	string listName = test->getName();

	EXPECT_EQ(listName, "");
}

TEST(TestingList, SettingDescription){
	int id2 = 2;
	int &id = id2;

	List* test = new List(id);
	test->setDescription("Finish project soon.");
	string listDescription = test->getDescription();
	
	EXPECT_EQ(listDescription, "Finish project soon.");
}

TEST(TestingList, EmptyDescription){
	int id2 = 2;
	int &id = id2;

	List* test = new List(id);
	test->setDescription("");
	string listDescription = test->getDescription();

	EXPECT_EQ(listDescription, "");
}

TEST(TestingList, SettingDueDate){
	int id2 = 3;
	int &id = id2;

	List* test = new List(id);
	test->setDueDate("November 30, 2021");
	string listDueDate = test->getDueDate();
	
	EXPECT_EQ(listDueDate, "November 30, 2021");
}

TEST(TestingList, EmptyDate){
	int id2 = 2;
	int &id = id2;

	List* test = new List(id);
	test->setDueDate("");
	string due = test->getDueDate();

	EXPECT_EQ(due, "");
}

TEST(TestingTask, TaskID){
	int id2 = 1;
	int &id = id2;

	Task* test = new Task(id);
	int ID = test->getID();
	
	EXPECT_EQ(ID,1 );
}

TEST(TestingTask, TaskName){
	int id2 = 1;
	int &id = id2;
	
	Task* test = new Task(id);
	test->setName("Task 1");
	string taskName = test->getName();

	EXPECT_EQ(taskName, "Task 1");
}

TEST(TestingTask, EmptyTaskName){
        int id2 = 1;
        int &id = id2;

        Task* test = new Task(id);
        test->setName("");
        string taskName = test->getName();

        EXPECT_EQ(taskName, "");
}
 
TEST(TestingTask, TaskDescription){
	int id2 = 2;
	int &id = id2;

	Task* test = new Task(id);
	test->setDescription("Finish tasks");
	string taskDescription = test->getDescription();

	EXPECT_EQ(taskDescription, "Finish tasks");
}

TEST(TestingTask, EmptyTaskDescription){
        int id2 = 2;
        int &id = id2;

        Task* test = new Task(id);
        test->setDescription("");
        string taskDescription = test->getDescription();

        EXPECT_EQ(taskDescription, "");
}

TEST(TestingTask, TaskPriority){
	int id2 = 1;
	int &id = id2;

	Task* test = new Task(id);
	test->setPriority(2);
	int priority = test->getPriority();

	EXPECT_EQ(priority, 2);
}

TEST(TestingTask, TaskDuration){
	int id2 = 1;
	int &id = id2;

	Task* test = new Task(id);
	test->setDuration(22);
	int d = test->getDuration();
	
	EXPECT_EQ(d, 22);
}
#endif //__DISPLAY_TEST_HPP__
