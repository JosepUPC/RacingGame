#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "ModulePlayer.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{
}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;
	ondeath.x = 0;
	ondeath.y = 15;
	ondeath.z = -200;

	for (uint c = 0; c < NCUBES; ++c) {
		Cube cube;
		cube.color = { 0.50f ,0.23f,0 };
		cube.size = 2;

		c_obstacles.PushBack(cube);
	}
	c_obstacles[0].size = 20;
	c_obstacles[0].SetPos(0, 4,  -200);
	c_obstacles[0].color = Red;	

	c_obstacles[1].size = 20;
	c_obstacles[1].SetPos(0, 4, - 178);
	c_obstacles[1].color = Red;

	c_obstacles[2].size = 12;
	c_obstacles[2].SetPos(0, 10, - 165);
	c_obstacles[2].color = Green;

	c_obstacles[3].size = 12;
	c_obstacles[3].SetPos(0, 12, - 155);
	c_obstacles[3].color = Green;

	c_obstacles[4].size = 7;
	c_obstacles[4].SetPos(0, 14, -145);
	c_obstacles[4].color = {0.63f, 0, 0.33f};
	c_obstacles[4].SetRotation(30.0f, vec3(1,0,0));

	c_obstacles[5].size = 5;
	c_obstacles[5].SetPos(0, 14, -135);
	c_obstacles[5].color = Green;
	c_obstacles[5].SetRotation(40.0f, vec3(1, 1, 0));

	c_obstacles[6].size = 7;
	c_obstacles[6].SetPos(0, 10, -123);
	c_obstacles[6].color = Blue;

	c_obstacles[7].size = 20;
	c_obstacles[7].SetPos(0, 15, -218);
	c_obstacles[7].color = Red;

	c_obstacles[8].size = 13;
	c_obstacles[8].SetPos(0, 10, -112);
	c_obstacles[8].color = { .63f, 0, .33f };

	c_obstacles[9].size = 13;
	c_obstacles[9].SetPos(0, 16, -98);
	c_obstacles[9].color = { .63f, 0, .33f };

	c_obstacles[10].size = 15;
	c_obstacles[10].SetPos(0, 20, -80);
	c_obstacles[10].color = Green;

	c_obstacles[11].size = 7;
	c_obstacles[11].SetPos(0, 20, -60);
	c_obstacles[11].color = Blue;

	c_obstacles[12].size = 40;
	c_obstacles[12].SetPos(0, 0, -35);
	c_obstacles[12].color = Green;

	c_obstacles[13].size = 3;
	c_obstacles[13].SetPos(0, 35, -20);
	c_obstacles[13].color = Red;

	c_obstacles[14].size = 4;
	c_obstacles[14].SetPos(0, 23, -20);
	c_obstacles[14].color = Red;

	c_obstacles[15].size = 20;
	c_obstacles[15].SetPos(0, 3, -2);
	c_obstacles[15].color = Green;

	c_obstacles[16].size = 6;
	c_obstacles[16].SetPos(0, 8, 33);
	c_obstacles[16].color = { .63f, 0, .33f };

	c_obstacles[17].size = 7;
	c_obstacles[17].SetPos(0, 8, 29);
	c_obstacles[17].color = Blue;

	c_obstacles[18].size = 10;
	c_obstacles[18].SetPos(0, 8, 75);
	c_obstacles[18].color = { .63f, 0, .33f };

	c_obstacles[19].size = 30;
	c_obstacles[19].SetPos(0, 3, 50);
	c_obstacles[19].color = Red;
	c_obstacles[19].SetRotation(25, { -1, 0, 0 });

	c_obstacles[20].size = 30;
	c_obstacles[20].SetPos(0, 3, 110);
	c_obstacles[20].color = Red;
	c_obstacles[20].SetRotation(15, { 1, 0, 0 });

	c_obstacles[21].size = 50;
	c_obstacles[21].SetPos(0, -11, 150);
	c_obstacles[21].color = Green;

	c_obstacles[22].size = 3;
	c_obstacles[22].SetPos(1, 3.1f, 140);
	c_obstacles[22].color = Red;
	
	c_obstacles[23].size = 3;
	c_obstacles[23].SetPos(-1, 3.1f, 144);
	c_obstacles[23].color = Red;

	c_obstacles[24].size = 3;
	c_obstacles[24].SetPos(-1, 3.1f, 148);
	c_obstacles[24].color = Red;

	c_obstacles[25].size = 3;
	c_obstacles[25].SetPos(1, 3.1f, 152);
	c_obstacles[25].color = Red;

	c_obstacles[26].size = 3;
	c_obstacles[26].SetPos(-1, 3.1f, 156);
	c_obstacles[26].color = Red;

	c_obstacles[28].size = 60;
	c_obstacles[28].SetPos(40, 0, 110);
	c_obstacles[28].color = Red;
	c_obstacles[28].SetRotation(40, { -1, 0, 0 });

	c_obstacles[29].size = 20;
	c_obstacles[29].SetPos(0, 10, 186);
	c_obstacles[29].color = Red;
	c_obstacles[29].SetRotation(40, { -1, 0, 0 });

	c_obstacles[30].size = 14;
	c_obstacles[30].SetPos(0, 18, 245);
	c_obstacles[30].color = Green;
	c_obstacles[30].SetRotation(40, { -1, 0, 1 });

	c_obstacles[31].size = 12;
	c_obstacles[31].SetPos(0, 18, 260);
	c_obstacles[31].color = Green;
	c_obstacles[31].SetRotation(50, { 1, 0, 0 });

	c_obstacles[32].size = 9 ;
	c_obstacles[32].SetPos(0, 18, 270);
	c_obstacles[32].color = Green;

	c_obstacles[33].size = 9;
	c_obstacles[33].SetPos(0, 18, 280);
	c_obstacles[33].color = Green;
	
	c_obstacles[34].size = 20;
	c_obstacles[34].SetPos(40, 10, 256);
	c_obstacles[34].SetRotation(40, { -1, 0, 0 });
	c_obstacles[34].color = Red;

	c_obstacles[35].size = 20;
	c_obstacles[35].SetPos(-20, 10, 256);
	c_obstacles[35].SetRotation(40, { -1, 0, 0 });
	c_obstacles[35].color = Red;

	c_obstacles[36].size = 40;
	c_obstacles[36].SetPos(0, 43, 322);
	c_obstacles[36].color = Green;



	c_obstacles[GOALCUBE].size = 20;
	c_obstacles[GOALCUBE].SetPos(0, 14, 295);
	c_obstacles[GOALCUBE].color = { 1,1,1 };


	block[0].body = App->physics->AddBody(c_obstacles[8], 0);
	block[0].LSpeed = { 0, 0.05f, 0 };
	block[0].id = 8;

	block[1].body = App->physics->AddBody(c_obstacles[9], 0);
	block[1].LSpeed = { 0, 0.05f, 0 };
	block[1].id = 9;

	block[2].body = App->physics->AddBody(c_obstacles[16], 0);
	block[2].LSpeed = { 0, 0.00f, 0.05f };
	block[2].id = 16;

	block[3].body = App->physics->AddBody(c_obstacles[18], 0);
	block[3].LSpeed = { 0, 0.2f, 0.00f };
	block[3].id = 18;

	block[4].body = App->physics->AddBody(c_obstacles[27], 0);
	block[4].LSpeed = { 0, 0.2f, 0.00f };
	block[4].id = 27;

	for (uint c = 0; c < c_obstacles.Count(); ++c) {
		PhysBody3D* body;
		float mass;
		if (c != block[0].id && c != block[1].id && c != block[2].id && c != block[3].id && c != block[4].id) {
			if (c == 14)
				mass = 50;
			else
				if (c > 22 && c < 26)
					mass = 0.3f;
				else
					mass = 0;
			body = App->physics->AddBody(c_obstacles[c], mass);
		}
		obstacles.PushBack(body);
	}

	vec3 AnchorA;
	vec3 AnchorB;

	AnchorA.x = 0;
	AnchorA.y = 0;
	AnchorA.z = 0;

	AnchorB = { 0, -13, 0 };

	App->physics->AddConstraintHinge(*obstacles[13], *obstacles[14], AnchorA, AnchorB, vec3(1, 0, 0), vec3(1, 0, 0));

	Cube p(5, 1, 1000);
	p.SetPos(0, 1, 0);

	sensor_fail = App->physics->AddBody(p, 0);
	sensor_fail->SetAsSensor(true);
	sensor_fail->collision_listeners.add(this);

	Cube check1(3, 10, 0.1);
	check1.SetPos(0, 15, -123);
	checkpoints[0] = App->physics->AddBody(check1, 0);
	checkpoints[0]->SetAsSensor(true);
	checkpoints[0]->collision_listeners.add(this);
	
	Cube check2(3, 10, 0.1);
	check2.SetPos(0, 25, -60);
	checkpoints[1] = App->physics->AddBody(check2, 0);
	checkpoints[1]->SetAsSensor(true);
	checkpoints[1]->collision_listeners.add(this);

	Cube check3(3, 10, 0.1);
	check3.SetPos(0, 12, 29);
	checkpoints[2] = App->physics->AddBody(check3, 0);
	checkpoints[2]->SetAsSensor(true);
	checkpoints[2]->collision_listeners.add(this);
	
	Cube fin(3, 30, 0.1);
	fin.SetPos(0, 18, 295);
	goal = App->physics->AddBody(fin, 0);
	goal->SetAsSensor(true);
	goal->collision_listeners.add(this);

	// FX -------------
	music = App->audio->LoadFx("Music/bgmusic.ogg");
	cpfx = App->audio->LoadFx("FX/Checkpoint.wav");
	yousuck = App->audio->LoadFx("FX/YouSuck.wav");
	bloodyspectacular = App->audio->LoadFx("FX/BloodySpectacular.wav");
	App->audio->PlayFx(music, -1);
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{

	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();


	for (uint c = 0; c < NCUBES; ++c) {
		obstacles[c]->GetTransform(c_obstacles[c].transform.M);
		if(c != 18)
			c_obstacles[c].Render();
	}

	c_obstacles[8].SetPos(block[0].body->GetBody()->getCenterOfMassPosition().x(), block[0].body->GetBody()->getCenterOfMassPosition().y(), block[0].body->GetBody()->getCenterOfMassPosition().z());
	c_obstacles[9].SetPos(block[1].body->GetBody()->getCenterOfMassPosition().x(), block[1].body->GetBody()->getCenterOfMassPosition().y(), block[1].body->GetBody()->getCenterOfMassPosition().z());
	c_obstacles[16].SetPos(block[2].body->GetBody()->getCenterOfMassPosition().x(), block[2].body->GetBody()->getCenterOfMassPosition().y(), block[2].body->GetBody()->getCenterOfMassPosition().z());
	c_obstacles[18].SetPos(block[3].body->GetBody()->getCenterOfMassPosition().x(), block[3].body->GetBody()->getCenterOfMassPosition().y(), block[3].body->GetBody()->getCenterOfMassPosition().z());


	if (block[0].body->GetBody()->getCenterOfMassPosition().y() > 15)
		block[0].backwards = true;
	if (block[0].body->GetBody()->getCenterOfMassPosition().y() < 6)
		block[0].backwards = false;

	if (block[1].body->GetBody()->getCenterOfMassPosition().y() > 22)
		block[1].backwards = true;
	if (block[1].body->GetBody()->getCenterOfMassPosition().y() < 9)
		block[1].backwards = false;

	if (block[2].body->GetBody()->getCenterOfMassPosition().z() > 24)
		block[2].backwards = true;
	if (block[2].body->GetBody()->getCenterOfMassPosition().z() < 12)
		block[2].backwards = false;

	if (block[3].body->GetBody()->getCenterOfMassPosition().y() > 55)
		block[3].backwards = true;
	if (block[3].body->GetBody()->getCenterOfMassPosition().y() < 6)
		block[3].backwards = false;

	block[0].Move();
	block[1].Move();
	block[2].Move();
	block[3].Move();

	c_obstacles[8].Render();
	c_obstacles[9].Render();
	c_obstacles[16].Render();
	c_obstacles[18].Render();


	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D * body1, PhysBody3D * body2)
{
	if (body1 == sensor_fail && body2 == App->player->vehiclepoint) {
		App->player->RestartCar();
	}
	if (body1 == checkpoints[0] && body2 == App->player->vehiclepoint) {
		if (ondeath.z != -123)
			App->audio->PlayFx(cpfx);
		ondeath.y = 15;
		ondeath.z = -123;
		c_obstacles[6].color = { .24f, .70f, .44f };
	} else if (body1 == checkpoints[1] && body2 == App->player->vehiclepoint) {
		if (ondeath.z != -60)
			App->audio->PlayFx(cpfx);
		ondeath.y = 25;
		ondeath.z = -60;
		c_obstacles[11].color = { .24f, .70f, .44f };
	}
 else if (body1 == checkpoints[2] && body2 == App->player->vehiclepoint) {
	 if (ondeath.z != 29)
		 App->audio->PlayFx(cpfx);
	 ondeath.y = 12;
	 ondeath.z = 29;

	 c_obstacles[17].color = { .24f, .70f, .44f };
 }
 else if (body1 == goal && body2 == App->player->vehiclepoint) {
	 ondeath.y = 15;
	 ondeath.z = -200;
	 App->player->vehiclepoint->SetPos(ondeath.x, ondeath.y, ondeath.z);
	 c_obstacles[6].color = Blue;
	 c_obstacles[11].color = Blue;
	 c_obstacles[17].color = Blue;
	 App->audio->PlayFx(bloodyspectacular);
	
	 if (App->player->best > App->player->time.Read()/1000 + App->player->deaths * 5 || App->player->best == 0)
	 App->player->best = ( (float)App->player->time.Read()/1000) + App->player->deaths * 5;
	 App->player->time.Start();
	 App->player->deaths = 0;
 }

}

void MBlock::Move() {
	float trans[16];
	body->GetTransform(trans);

	if (backwards == false) {
		body->SetPos(trans[12] + LSpeed.x, trans[13] + LSpeed.y, trans[14] + LSpeed.z);
	}
	else {
		body->SetPos(trans[12] - LSpeed.x, trans[13] - LSpeed.y, trans[14] - LSpeed.z);
	}

}