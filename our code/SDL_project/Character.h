#pragma once
#include"Level.h"

class CharacterState; //forward declartion I think

//!  The abstract character class 
/*!
  This class is the base for the main character and the NPC. It contains all the functions
  needed to make the character move and react to different states.
*/
class Character
{
public:
	//! A constructor
	Character();
	//! A destructor
	~Character();
		
	//Getter methods
	//! Gets the characters X value
	int getX() { return x; }
	//! Gets the characters Y value
	int getY() { return y; }
	//! Gets the characters size
	int getSize() { return size; }
	//! Gets the characters speed
	int getSpeed() { return speed; }

	//Setter methods
	//! Sets the characters X value
	int setX(int newX) { return x = newX; }
	//! Sets the characters Y value
	int setY(int newY) { return y = newY; }
	//! Sets the characters current speed
	int setSpeed(int newSpeed) { return speed = newSpeed; }
	
	//! Shared pointer to the Level loaded in SpaceGame
	std::shared_ptr<Level> currentRoom;

	//Cell checking functions
	//! Checks whether a cell is a room
	bool isCellARoom(int x, int y);
	//! Checks whether a cell is a door
	bool isCellADoor(int x, int y);
	//! Checks whether a cell is a room but not a door
	bool canWanderInRoom(int x, int y);
	//! Gets the oxygen level of a given room
	int getOxygenLevel(int x, int y);

	//! Changes the character's X and Y value depending on the player's input
	void moveCharacter(const Uint8* keyboardState);
	//! Makes the character move in a random direction to look like they're wandering
	void wanderAroundRoom();
	
	//! An shared pointer to the character's state.
	std::shared_ptr<CharacterState> state;
	
	//! A double for the character's health
	double health = 100;
	//! Boolean for whether character is alive
	bool isAlive = true; 
	//! Integer for the random direction
	/*!
		Direction is used to decide the diretion the character 
		will move in when in the wandering state
	*/
	int direction = 1;
	//! Integer to store time spent in a state
	double timer = 0;
	//! Integers for the different movement speeds
	int suffocatingSpeed = 1, wanderSpeed = 2, walkSpeed = 3, runSpeed = 3;

private:
	//! Integers for the character's X and Y position
	int x = 50, y = 50;
	//! Integer for the character's size when rendered
	int size = 50;
	//! Integer for the characters current speed
	int speed = 3; 
};

