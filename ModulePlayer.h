#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "Time.h"
struct PhysVehicle3D;

#define MAX_ACCELERATION 800.0f
#define TURN_DEGREES 15.0f * DEGTORAD
#define BRAKE_POWER 1000.0f


class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void RestartCar();

public:
	PhysVehicle3D* vehicle;
	PhysBody3D* MotoJoint;
	PhysBody3D* vehiclepoint;
	float turn;
	float acceleration;
	float brake;

	Timer time;
	uint deaths;
	float best;
	uint startmotor;
	uint gas;

};