#pragma once

#include <windows.h>

typedef DWORD Void;
typedef DWORD Any;
typedef DWORD uint;
typedef DWORD Hash;
typedef int Entity;
typedef int Player;
typedef int FireId;
typedef int Ped;
typedef int Vehicle;
typedef int Cam;
typedef int CarGenerator;
typedef int Group;
typedef int Train;
typedef int Pickup;
typedef int Object;
typedef int Weapon;
typedef int Interior;
typedef int Blip;
typedef int Texture;
typedef int TextureDict;
typedef int CoverPoint;
typedef int Camera;
typedef int TaskSequence;
typedef int ColourIndex;
typedef int Sphere;

#pragma pack(push, 1)
typedef struct
{
	float x;
	DWORD _paddingx;
	float y;
	DWORD _paddingy;
	float z;
	DWORD _paddingz;
} Vector3;
#pragma pack(pop)

typedef struct{ int R, G, B, A; } RGBA;
typedef struct { float _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10; } Float10;
typedef struct { float r, g, b; } RGBFloat;
typedef struct { char* NotificationText; int NotificationState, NotificationTimer, NotificationSpriteAlpha; float NotificationTextX, NotificationSpriteX, NotificationY, speed; } Notification;