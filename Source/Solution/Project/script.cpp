#include "script.h"
#include "keyboard.h"
#include "Convert.h"
#include <string>
#include <ctime>
#include <cstdint>
#include <Windows.h>
#include <string>
#include <vector>
#include <cstdio>
#include <Psapi.h>
#pragma warning(disable : 4244 4305) // double <-> float conversions

namespace SUB{enum{
// Define submenu (enum) indices here.
			CLOSED,
			MAINMENU,
			SETTINGS,
			SETTINGS_COLOURS,
			SETTINGS_COLOURS2,
			SETTINGS_FONTS,
			SETTINGS_FONTS2,
	// Others:
			SAMPLE,
			YOURSUB,
			ONLINEPLAYERS,
			PLAYER,
			VEHICLE1,
			MISC,
			RECOVERY,
			TELEPORT,
			INSIDEBUILDINGS,
			CARCOLORS,
			PRIMARY,
			SECONDARY,
			ONLINEPLAYER,
			MODSHOP,
			ARMOUR,
			ENGINE,
			TRANSMISSION,
			BRAKES,
			SUSPENSION,
			EXHAUST,
			TURBO,
			FRONTB_MENU,
			REARB_MENU,
			SIDE_SKIRTS,
			HOODS,
			SPOILER,
			VEHICLESPAWNER,
			PEGASUSP,
			ALLPLAYERS,
			IPLLOADER,
			NORTHYANKTON,
			MODELCHANGER,
			IGG,
			YACHT,
			HYACT,
			HCARRIER,
			DHOSPITAL,
			JSTORE,
			MORGUE,
			CSHIP,
			ONRANCH,
			BONRANCH,
			LLOBBY,
			FIBLOBBY,
			TCRASH,
			BSHOUSE,
			PCRASH,
			CBELL,
			UFO,
			OBJECTSPAWNER,
			PEDSPAWNER,
			WEAPONS,
			NEON,
			NEONL,
			NEONC,
			LOCALONLINE,
			CUSTOMPRIMARY,
			CUSTOMSECONDARY,
			VSSUPER,
			VSSPORTS,
			VSSPORTSC,
			MUSCLE,
			SEDANS,
			COUPES,
			COMPACT,
			SUVANDTRUCK,
			OFFROAD,
			ONLINEVEHICLE,
			PEDOPTIONS,
			PED,
			PEDSPAWNERSETTINGS,
			MULTIPLIERS,
			CUSTOMBULLETS,
			ROOF,
			GRILLE,
			BETA,
			SAVELOADVEHICLE,
			SAVEDVEHICLES,
			DEVMENU,
			HORN,
			WHEELS,
			WHEELTYPE,
			SELECTWHEEL,
			ANIMATIONS,
			ONLINEBLAMEPLAYER,
			SCENARIOS,
			OBJECTOPTIONS,
			OBJECT,
			PEDSPAWNERXYZ,
			SPEEDOMETERMENU,
			COMPONENTSELECTOR,
			COMPONENTCHANGER,
			VSVANS,
			VSEMERGENCY,
			VSSERVICE,
			VSMILITARY,
			VSMOTORCYCLES,
			VSBICYCLES,
			VSCOMMERCIAL,
			VSHELICOPTERS,
			VSPLANES,
			VSBOATS,
			VSTRAILERS,
			VSSETTINGS,
			ADDCUSTOMOBJECT,
			PEDSPAWNERWEAPONSELECTION,
			VEHWEAPONSMENU,
			LOWRIDERDLC,
			BAHAMAMAMAS,
			CUSTOMVEHMOD,
			BENNYS,
			BENNYSMODS,
			VEHINTERIOR,
			VEHINTERIORCOLOR,
			VEHDASHBOARDCOLOR,
			MODLABELS,
			VEHTRIM,
			PRESETCUSTOMCOLORS,
			PRESETCUSTOMSECONDARY,
			LIGHTS,
			HEADLIGHTS,
			NEOCUSTOMRGB,
			PTFXTEST,
			COMPONENTCHANGERPROP,
			WEATHER,
			DOORMENU,
			SAVEDVEHEDITOR,
			CUSTOMVEHCATEGORY,
			ADDTOCUSTOMVEHICLES,
			DELTEFROMCUSTOMVEHICLES,
			PRIMARYCOLORCLASSIC,
			PRIMARYCOLORMATTE,
			PRIMARYCOLORMETALIC,
			SECONDARYCOLORCLASSIC,
			SECONDARYCOLORMATTE,
			SECONDARYCOLORMETALIC,

			


};};
namespace Array {
	enum {
		WeaponModels,
		allvehModels,
		ColorNames
	};
};
namespace{
// Declare/Initialise global variables here.
char str[50];
bool controllerinput_bool = 1, menujustopened = 1, null;
int *settings_font, inull;
RGBA *settings_rgba;
RGBA titlebox = { 0, 210, 0, 255 };
RGBA BG = { 20, 20, 20, 255 };
RGBA titletext = { 255, 255, 255, 255 };
RGBA optiontext = { 255, 255, 255, 255 };
RGBA optioncount = { 0, 140, 0, 255 };
RGBA selectedtext = { 0, 140, 0, 250 };
RGBA optionbreaks = { 0, 140, 0, 250 };
RGBA selectionhi = { 250, 250, 250, 255 };
int font_title = 1, font_options = 4, font_selection = 4, font_breaks = 4;
float menuPos = 0, OptionY;
int screen_res_x, screen_res_y;
DWORD myVeh, cam_gta2;
float current_timescale = 1.0f;
bool gradients = 1;
float menuScaleX = 0, menuScaleY = 0;



// Booleans for loops go here:
bool loop_massacre_mode = 0, loop_RainbowBoxes = 0, loop_gravity_gun = 0, loop_gta2cam = 0, activenos = 0, vehWeaponsCheck = 0, superruncheck = 0, boost_check = 0, sbrake_check = 0, carjump_check = 0, fixcar_check = 0, neverwanted_check = 0, UnlimitedAbility_check = 0, superjump_check = 0, Test1_check = 0, ammo_check = 0, driveunderwater_check = 0, godmode_check = 0, fwgun_check = 0, cash_check = 0, Drive_on_water = 0, brawler_check = 0, TrainSpeedControlCheck = 0, TorqueMultiCheck = 0, customBulletsCheck = 0, DriveTrainCheck = 0, RainbowCarCheck = 0, SuperManualCheck = 0, blackout = 0, speedometerCheck = 0, SnowCheck = 0, DebugMode = 0, FreeCam = 0, visibleCheck = 1, MTaxi = 0, LoopNotification = 0, VehWeaponAtKeyDown = 0, SwitchingSubmenu = 0, BetaFeatures = 0, draw_fps = 0, ModJustLoadedCheck = 1, tmpvehCreated = 0, RainbowNeonCheck = 0, Draw_Coords = 0, ColorAnimationRunning = 0, TSlowStop = 0, AllowLowrider2 = 0, missionEntityLoop = 0, CrashAvoid = 0, CustomVehEditMode = 0;
}
int selectedPlayer = 0;
char* Model = "";
char* PlateType = "";
int TorqueMultiValue;
Vehicle SaveTest;
int pRed = 0, pGreen = 0, pBlue = 0;
int sRed = 0, sGreen = 0, sBlue = 0;
int rpRed = 0, rpGreen = 0, rpBlue = 0;
int rsRed = 0, rsGreen = 0, rsBlue = 0;
bool pRedMinus = 0, sRedMinus = 0, pBlueMinus = 0, sBlueMinus = 0, pGreenMinus = 0, sGreenMinus = 0, NeonRMinus = 0, NeonGMinus = 0, NeonBMinus = 0;
bool VSDeleteLast = 1, VSSpawnInside = 1, VSSpawnUpgaraded = 0, VSSpawnWithCustomPlate = 0, SetPlateText = 0;
char* WindowTint = "", *WheelTypeChar = "", *componentChangerCompmentName = "", *MapType = "SP", *CustomPlateType = "North Yankton", *CustomPlateText = "", *SelectedVehWeaponModel = "", *Bennysmodname = "";
int WheelsAmount = 0, WheeltypeInt = 0, wantedlevel = 0, SelectedObject = 0, componentChangerId = 0, componentChangerdrawableId = 0, componentChangerTextureId = 0, VSCustomPlateType = 5, PedSpawnerSlots = 100, ObjectSpawnerslots = 2048, SubmenuSwithState = 0, _subindex, MaxVehMod = 0, bennysmodType = 0, StockVehModIndex = 4294967295, NotificationCount = 0, customVehiclesCount = 0;
Object ObjectSlot;
char *ObjecSlotName;
bool ObjectSlotUsed[2048];
Object ObjectSlots[2048];
char* ObjectSlotsName[2048];
int tmpvar1, tmpvar2, tmpvar3;
char *CustomVehicleNames[100];
Hash CustomvehicleModels[100];
// PEDS
Ped PED1;
Ped AlienPed;
// Vehicles
Vehicle Train1, TMPVehicle, AnimateColorVeh;
float TrainSpeed, WaterHeight;
Object DriveOnWaterObject;
// PedSpawnerSlots
char* NameSlot = "";
bool PedSpawnInvincible = 0, PedSpawnAsBodyguard = 0, PedSpawnWithCombatMg = 0, PedSpawnWithBlip = 1;
bool FreezePed = 0;
int SelectedPedSlot;
Vector3 PedSpawnerCoords;
static Ped PedSlots[100];
static bool PedSlotUsed[100];
static char* PedNameSlot[100];
static Blip BlipPedSlots[100];
static bool PedSpawnWithWeapon[66];
// Custom Bullets
bool CBMoneyBag = 0, CBTeleGun = 0, CBRpg = 0, CBVehGun = 0;
// Vehicle Save/Load
bool VehSaved[1000];
int SavedVehMods[1000][100];
int SavedVehColor1[1000], SavedVehColor2[1000], SavedVehColorPR[1000], SavedVehColorPG[1000], SavedVehColorPB[1000], SavedVehColorSR[1000], SavedVehColorSG[1000], SavedVehColorSB[1000];
char* SavedVehName[1000];
Hash SavedVehModel[1000];
int selectedSavedVeh = 0;
//
RGBA NeonColor, ColorToAnimateTo;
RGBFloat animationSpeed, ColorAnimationColor;
bool DisplayKeyboard = 0, OnscreenKeyboardDisplayed = 0;
static bool SelectedVehWeapon[20], StoredSelectedVehWeapon[20];
char* ObjectSpawnerCustom1Name = "", *ObjectSpawnerCustom2Name = "", *ObjectSpawnerCustom3Name = "", *ObjectSpawnerCustom4Name = "", *ObjectSpawnerCustom5Name = "", *ObjectSpawnerCustom6Name = "", *ObjectSpawnerCustom7Name = "", *ObjectSpawnerCustom8Name = "", *ObjectSpawnerCustom9Name = "", *ObjectSpawnerCustom10Name = "", *CustomObject1Model = "", *CustomObject2Model = "", *CustomObject3Model = "", *CustomObject4Model = "", *CustomObject5Model = "", *CustomObject6Model = "", *CustomObject7Model = "", *CustomObject8Model = "", *CustomObject9Model = "", *CustomObject10Model = "";
bool CustomObject1Used = 0, CustomObject2Used = 0, CustomObject3Used = 0, CustomObject4Used = 0, CustomObject5Used = 0, CustomObject6Used = 0, CustomObject7Used = 0, CustomObject8Used = 0, CustomObject9Used = 0, CustomObject10Used = 0;
float DebugPos[5] = { 0.0, 0.04, 0.08, 0.12, 0.16 }, DebugTextsPrinted = 0;
Notification notifications[10];
char* DebugTexts[5] = {"", "", "", "", ""},/*
      *candc_default[28] = { "airbus", "barracks", "boxville4", "bus", "buzzard", "cargobob", "coach", "crusader", "dubsta3", "dukes", "dukes2", "dump", "hydra", "insurgent", "insurgent2", "journey", "marshall", "mesa", "mesa3", "monster", "mule", "mule3", "pbus", "rentbus", "rhino", "savage", "technical", "valkyrie"},
      *dock_default[10] = { "dinghy3", "jetmax", "marquis", "seashark", "speeder", "squalo", "sub2", "suntrap", "toro", "tropic"},
	  *elt_default[13] = { "annihl", "cuban800", "dodo", "duster", "frogger", "luxor", "mammatus", "maverick", "shamal", "stunt", "titan", "velum", "velum2" },
	  *elt_dlc_business[1] = { "vestra" },
	  *elt_dlc_luxe[] = { "", "" },
	  *elt_dlc_pilot[] = { "", "" },
      *lgm_default[29] = { "adder", "banshee", "bullet", "carbon", "carboniz", "cheetah", "cogcabri", "comet2", "coquette", "elegy2", "entityxf", "exemplar", "feltzer", "hotknife", "infernus", "jb700", "khamel", "monroe", "ninef", "ninef2", "rapidgt", "rapidgt2", "stinger", "stingerg", "superd", "surano_convertable", "vacca", "voltic_tless", "ztype" },
	  *lgm_dlc_business[3] = { "alpha", "jester", "turismor" },
	  *lgm_dlc_business2[8] = { "banshee_tless", "coquette_tless", "huntley", "massacro", "stinger_tless", "thrust", "voltic_htop", "zentorno" },
	  *lgm_dlc_heist[2] = { "casco", "lectro" },
	  *lgm_dlc_its_creator[1] = { "furore" },
	  *lgm_dlc_luxe[11] = { "brawler", "chino", "coquette3", "feltzer3", "luxor2", "osiris", "swift2", "t20", "vindicator", "virgo", "windsor" },
	  *lgm_dlc_pilot[5] = { "besra", "coquette2", "coquette2_tless", "miljet", "swift" },
	  *lgm_dlc_valentines[1] = { "roosevelt" },
	  *pandm_default[6] = { "bmx", "cruiser", "scorcher", "tribike", "tribike2", "tribike3" },
	  *sssa_default[47] = { "akuma", "baller2", "banshee", "bati", "bati2", "bfinject", "bifta", "bison", "blazer", "bodhi2", "cavcade", "comet2", "dilettan", "double", "dune", "exemplar", "faggio", "felon", "felon2", "feltzer", "fugitive", "gauntlet", "hexer", "infernus", "issi2", "kalahari", "ninef", "oracle", "paradise", "pcj", "rebel", "rocoto", "ruffian", "sadler", "sanchez", "sanchez2", "sandkin2", "sandking", "schwarze", "stretch", "superd", "surano", "vacca", "vader", "vigero", "zion", "zion2" },
	  *sssa_dlc_business[14] = { "asea", "astrope", "bobcatxl", "cavcade2", "granger", "ingot", "intruder", "minivan", "premier", "radi", "rancherx", "stanier", "stratum", "washingt" },
	  *sssa_dlc_business2[6] = { "dominato", "f620", "fusilade", "penumbra", "sentinel", "sentinel_convertable" },
	  *sssa_dlc_christmas_2[4] = { "jester2", "massacro2", "rloader2", "slamvan" },
	  *sssa_dlc_heist[16] = { "blade", "enduro", "gburrito2", "gresley", "guardian", "innovation", "jackal", "kuruma", "kuruma2", "landstalker", "nemesis", "oracle1", "rumpo", "schafter2", "seminole", "surge" },
	  *sssa_dlc_hipster[16] = { "blade", "blazer3", "buffalo", "buffalo2", "glendale", "panto", "picador", "pigalle", "primo", "rebel2", "regina", "rhapsody", "surfer", "tailgater", "warrener", "youga" },
	  *sssa_dlc_independece[1] = { "sovereign" },
	  *sssa_dlc_its_creator[3] = { "hakuchou", "innovation", "kalahari_topless" },
	  *sssa_dlc_mp_to_sp[7] = { "blista2", "buffalo3", "dominator2", "dukes", "gauntlet2", "stalion2", "stallion" },
	  *sssa_dlc_valentines[1] = { "rloader" },
	  *WeaponModels[56] = { "WEAPON_KNIFE", "WEAPON_NIGHTSTICK", "WEAPON_HAMMER", "WEAPON_BAT", "WEAPON_GOLFCLUB", "WEAPON_CROWBAR", "WEAPON_PISTOL", "WEAPON_COMBATPISTOL", "WEAPON_APPISTOL", "WEAPON_PISTOL50", "WEAPON_MICROSMG", "WEAPON_SMG", "WEAPON_ASSAULTSMG", "WEAPON_ASSAULTRIFLE", "WEAPON_CARBINERIFLE", "WEAPON_ADVANCEDRIFLE", "WEAPON_MG", "WEAPON_COMBATMG", "WEAPON_PUMPSHOTGUN", "WEAPON_SAWNOFFSHOTGUN", "WEAPON_ASSAULTSHOTGUN", "WEAPON_BULLPUPSHOTGUN", "WEAPON_STUNGUN", "WEAPON_SNIPERRIFLE", "WEAPON_HEAVYSNIPER", "WEAPON_GRENADELAUNCHER", "WEAPON_GRENADELAUNCHER_SMOKE", "WEAPON_RPG", "WEAPON_MINIGUN", "WEAPON_GRENADE", "WEAPON_STICKYBOMB", "WEAPON_SMOKEGRENADE", "WEAPON_BZGAS", "WEAPON_MOLOTOV", "WEAPON_FIREEXTINGUISHER", "WEAPON_PETROLCAN", "WEAPON_SNSPISTOL", "WEAPON_SPECIALCARBINE", "WEAPON_HEAVYPISTOL", "WEAPON_BULLPUPRIFLE", "WEAPON_HOMINGLAUNCHER", "WEAPON_PROXMINE", "WEAPON_SNOWBALL", "WEAPON_VINTAGEPISTOL", "WEAPON_DAGGER", "WEAPON_FIREWORK", "WEAPON_MUSKET", "WEAPON_MARKSMANRIFLE", "WEAPON_HEAVYSHOTGUN", "WEAPON_GUSENBERG", "WEAPON_HATCHET", "WEAPON_RAILGUN", "WEAPON_COMBATPDW", "WEAPON_KNUCKLE", "WEAPON_MARKSMANPISTOL", "WEAPON_FLASHLIGHT" },
      *allvehModels[361] = { "NINEF", "NINEF2", "BLISTA", "ASEA", "ASEA2", "BOATTRAILER", "BUS", "ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "SUNTRAP", "COACH", "AIRBUS", "ASTEROPE", "AIRTUG", "AMBULANCE", "BARRACKS", "BARRACKS2", "BALLER", "BALLER2", "BJXL", "BANSHEE", "BENSON", "BFINJECTION", "BIFF", "BLAZER", "BLAZER2", "BLAZER3", "BISON", "BISON2", "BISON3", "BOXVILLE", "BOXVILLE2", "BOXVILLE3", "BOBCATXL", "BODHI2", "BUCCANEER", "BUFFALO", "BUFFALO2", "BULLDOZER", "BULLET", "BLIMP", "BURRITO", "BURRITO2", "BURRITO3", "BURRITO4", "BURRITO5", "CAVALCADE", "CAVALCADE2", "POLICET", "GBURRITO", "CABLECAR", "CADDY", "CADDY2", "CAMPER", "CARBONIZZARE", "CHEETAH", "COMET2", "COGCABRIO", "COQUETTE", "CUTTER", "GRESLEY", "DILETTANTE", "DILETTANTE2", "DUNE", "DUNE2", "HOTKNIFE", "DLOADER", "DUBSTA", "DUBSTA2", "DUMP", "RUBBLE", "DOCKTUG", "DOMINATOR", "EMPEROR", "EMPEROR2", "EMPEROR3", "ENTITYXF", "EXEMPLAR", "ELEGY2", "F620", "FBI", "FBI2", "FELON", "FELON2", "FELTZER2", "FIRETRUK", "FLATBED", "FORKLIFT", "FQ2", "FUSILADE", "FUGITIVE", "FUTO", "GRANGER", "GAUNTLET", "HABANERO", "HAULER", "HANDLER", "INFERNUS", "INGOT", "INTRUDER", "ISSI2",
"JACKAL", "JOURNEY", "JB700", "KHAMELION", "LANDSTALKER", "LGUARD", "MANANA", "MESA", "MESA2", "MESA3", "CRUSADER", "MINIVAN", "MIXER", "MIXER2", "MONROE", "MOWER", "MULE", "MULE2", "ORACLE", "ORACLE2", "PACKER", "PATRIOT", "PBUS", "PENUMBRA", "PEYOTE", "PHANTOM", "PHOENIX", "PICADOR", "POUNDER", "POLICE", "POLICE4", "POLICE2", "POLICE3", "POLICEOLD1", "POLICEOLD2", "PONY", "PONY2", "PRAIRIE", "PRANGER", "PREMIER", "PRIMO", "PROPTRAILER", "RANCHERXL", "RANCHERXL2", "RAPIDGT", "RAPIDGT2", "RADI", "RATLOADER", "REBEL", "REGINA", "REBEL2", "RENTALBUS", "RUINER", "RUMPO", "RUMPO2", "RHINO", "RIOT", "RIPLEY", "ROCOTO", "ROMERO", "SABREGT", "SADLER", "SADLER2", "SANDKING", "SANDKING2", "SCHAFTER2", "SCHWARZER", "SCRAP", "SEMINOLE", "SENTINEL", "SENTINEL2", "ZION", "ZION2", "SERRANO", "SHERIFF", "SHERIFF2", "SPEEDO", "SPEEDO2", "STANIER", "STINGER", "STINGERGT", "STOCKADE", "STOCKADE3", "STRATUM", "SULTAN", "SUPERD", "SURANO", "SURFER", "SURFER2", "SURGE", "TACO", "TAILGATER", "TAXI", "TRASH", "TRACTOR", "TRACTOR2", "TRACTOR3", "GRAINTRAILER", "BALETRAILER", "TIPTRUCK", "TIPTRUCK2", "TORNADO", "TORNADO2", "TORNADO3", "TORNADO4", "TOURBUS",
"TOWTRUCK", "TOWTRUCK2", "UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3", "VOODOO2", "WASHINGTON", "STRETCH", "YOUGA", "ZTYPE", "SANCHEZ", "SANCHEZ2", "SCORCHER", "TRIBIKE", "TRIBIKE2", "TRIBIKE3", "FIXTER", "CRUISER", "BMX", "POLICEB", "AKUMA", "CARBONRS", "BAGGER", "BATI", "BATI2", "RUFFIAN", "DAEMON", "DOUBLE", "PCJ", "VADER", "VIGERO", "FAGGIO2", "HEXER", "ANNIHILATOR", "BUZZARD", "BUZZARD2", "CARGOBOB", "CARGOBOB2", "CARGOBOB3", "SKYLIFT", "POLMAV", "MAVERICK", "NEMESIS", "FROGGER", "FROGGER2", "CUBAN800", "DUSTER", "STUNT", "MAMMATUS", "JET", "SHAMAL", "LUXOR", "TITAN", "LAZER", "CARGOPLANE", "SQUALO", "MARQUIS", "DINGHY", "DINGHY2", "JETMAX", "PREDATOR", "TROPIC", "SEASHARK", "SEASHARK2", "SUBMERSIBLE", "TRAILERS", "TRAILERS2", "TRAILERS3", "TVTRAILER", "RAKETRAILER", "TANKER", "TRAILERLOGS", "TR2", "TR3", "TR4", "TRFLAT", "TRAILERSMALL", "VELUM", "ADDER", "VOLTIC", "VACCA", "BIFTA", "SPEEDER", "PARADISE", "KALAHARI", "JESTER", "TURISMOR", "VESTRA", "ALPHA", "HUNTLEY", "THRUST", "MASSACRO", "MASSACRO2", "ZENTORNO", "BLADE", "GLENDALE", "PANTO", "PIGALLE", "WARRENER", "RHAPSODY", "DUBSTA3", "MONSTER", "SOVEREIGN", "INNOVATION",
"HAKUCHOU", "FUROREGT", "MILJET", "COQUETTE2", "BTYPE", "BUFFALO3", "DOMINATOR2", "GAUNTLET2", "MARSHALL", "DUKES", "DUKES2", "STALION", "STALION2", "BLISTA2", "BLISTA3", "DODO", "SUBMERSIBLE2", "HYDRA", "INSURGENT", "INSURGENT2", "TECHNICAL", "SAVAGE", "VALKYRIE", "KURUMA", "KURUMA2", "JESTER2", "CASCO", "VELUM2", "GUARDIAN", "ENDURO", "LECTRO", "SLAMVAN", "SLAMVAN2", "RATLOADER2", "SWIFT2", "LUXOR2", "FELTZER3", "OSIRIS", "VIRGO", "WINDSOR", "BESRA", "SWIFT", "BLIMP2", "VINDICATOR", "TORO", "T20", "COQUETTE3", "CHINO", "BRAWLER" },*/
      *ColorNames[161] = { "Black", "Graphite", "Black Steel", "Dark Steel", "Silver", "Bluish Silver", "Rolled Steel", "Shadow Silver", "Stone Silver", "Midnight Silver", "Cast Iron Silver", "Anthracite Black", "Matte Black", "Matte Gray", "Light Gray", "Util Black", "Util Black Poly", "Util Dark Silver", "Util Silver", "Util Gun Metal", "Util Shadow Silver", "Worn Black", "Worn Graphite", "Worn Silver Grey", "Worn Silver", "Worn Blue Silver", "Worn Shadow Silver", "Red", "Torino Red", "Formula Red", "Blaze Red", "Grace Red", "Garnet Red", "Sunset Red", "Cabernet Red", "Candy Red", "Sunrise Orange", "Gold", "Orange", "Red", "Dark Red", "Matte Orange", "Yellow", "Util Red", "Util Bright Red", "Util Garnet Red", "Worn Red", "Worn Golden Red", "Worn Dark Red", "Dark Green", "Metallic Racing Green", "Sea Green", "Olive Green", "Bright Green", "Metallic Gasoline Green", "Matte Lime Green", "Dark Green", "Worn Green", "Worn Sea Wash", "Metallic Midnight Blue", "Metallic Dark Blue", "Galaxy Blue", "Dark Blue", "Saxon Blue", "Blue", "Mariner Blue", "Harbor Blue", "Diamond Blue", "Surf Blue", "Nautical Blue", "Ultra Blue", "Schafter Purpler",
"Metallic Ultra Blue", "Racing Blue", "Light Blue", "Util Midnight Blue", "Util Blue", "Util Sea Foam Blue", "Util Lightning Blue", "Util Maui Blue Poly", "Util Bright Blue", "Slate Blue", "Dark Blue", "Blue", "Matte Midnight Blue", "Worn Dark Blue", "Worn Blue", "Baby Blue", "Yellow", "Race Yellow", "Bronze", "Dew Yellow", "Metallic Lime", "Metallic Champagne", "Feltzer Brown", "Creek Brown", "Chocolate Brown", "Maple Brown", "Saddle Brown", "Straw Brown", "Moss Brown", "Bison Brown", "Woodbeech Brown", "Beechwood Brown", "Straw Brown", "Sandy Brown", "Bleached Brown", "Cream", "Util Brown", "Util Medium Brown", "Util Light Brown", "Ice White", "Frost White", "Worn Honey Beige", "Worn Brown", "Dark Brown", "Worn Straw Beige", "Brushed Steel", "Brushed Black Steel", "Brushed Alluminum", "Chrome", "Worn Off-White", "Util Off-White", "Worn Orange", "Worn Light Orange", "Pea Green", "Worn Taxi Yellow", "Police Blue", "Green", "Matte Brown", "Worn Orange", "Ice White", "Worn White", "Worn Olive Army Green", "Pure White", "Hot Pink", "Salmon Pink", "Pfister Pink", "Bright Orange", "Green", "Flourescent Blue", "Midnight Blue",
"Midnight Purple", "Wine Red", "Hunter Green", "Bright Purple", "Midnight Purple", "Carbon Black", "Matte Purple", "Matte Dark Purple", "Metallic Lava Red", "Olive Green", "Matte Olive Drab", "Dark Earth", "Desert Tan", "Matte Foilage Green", "DEFAULT ALLOY", "Epsilon Blue", "Pure Gold", "Brushed Gold", "Secret Gold" };
namespace{
// Declare subroutines here.



}
namespace{
// Define subroutines here.

void VectorToFloat(Vector3 unk, float *Out)
{
	Out[0] = unk.x;
	Out[1] = unk.y;
	Out[2] = unk.z;
}
int RandomRGB()
{
	srand(GetTickCount());
	return (GET_RANDOM_INT_IN_RANGE(0, 255));
}
bool get_key_pressed(int nVirtKey)
{
	return (GetAsyncKeyState(nVirtKey) & 0x8000) != 0;
}
bool Check_self_in_vehicle()
{
	if (IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), 0)) return true; else return false;
}
int FindFreeCarSeat(DWORD vehicle)
{
	int max = GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS(vehicle) - 2;
	for (static int tick = -1; tick <= max; tick++)
	{
		if (IS_VEHICLE_SEAT_FREE(vehicle, tick))
		{
			return tick;
		}
	}

	return -1;
}
void offset_from_entity(int entity, float X, float Y, float Z, float * Out)
{
	VectorToFloat(GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(entity, X, Y, Z), Out);
}
void RequestControlOfEnt(DWORD entity)
{
	int tick = 0;

	while (!NETWORK_HAS_CONTROL_OF_ENTITY(entity) && tick <= 12)
	{
		NETWORK_REQUEST_CONTROL_OF_ENTITY(entity);
		tick++;
	}
}
void RequestControlOfid(DWORD netid)
{
	int tick = 0;

	while (!NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 12)
	{
		NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}
void RequestModel(DWORD Hash)
{
	REQUEST_MODEL(Hash);
	while (!(HAS_MODEL_LOADED(Hash)))
	{
		WAIT(5);
	}
}
int PlaceObject(DWORD Hash, float X, float Y, float Z, float Pitch, float Roll, float Yaw)
{
	RequestModel(Hash);
	static DWORD object = CREATE_OBJECT(Hash, X, Y, Z, 1, 1, 0);
	SET_ENTITY_ROTATION(object, Pitch, Roll, Yaw, 2, 1);
	FREEZE_ENTITY_POSITION(object, 1);
	SET_ENTITY_LOD_DIST(object, 696969);
	SET_MODEL_AS_NO_LONGER_NEEDED(Hash);
	SET_OBJECT_AS_NO_LONGER_NEEDED(&object);

	return object;
}
void setupdraw()
{
	SET_TEXT_FONT(0);
	SET_TEXT_SCALE(menuScaleX + 0.4f, menuScaleY + 0.4f);
	SET_TEXT_COLOUR(255, 255, 255, 255);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(0);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	SET_TEXT_EDGE(0, 0, 0, 0, 0);
	SET_TEXT_OUTLINE();
}
void drawstring(char* text, float X, float Y)
{
	_SET_TEXT_ENTRY("STRING");
	_ADD_TEXT_COMPONENT_STRING(text);
	_DRAW_TEXT(X, Y);
}
void drawinteger(int text, float X, float Y)
{
	_SET_TEXT_ENTRY("NUMBER");
	ADD_TEXT_COMPONENT_INTEGER(text);
	_DRAW_TEXT(X, Y);
}
void drawfloat(float text, DWORD decimal_places, float X, float Y)
{
	_SET_TEXT_ENTRY("NUMBER");
	ADD_TEXT_COMPONENT_FLOAT(text, decimal_places);
	_DRAW_TEXT(X, Y);
}
void PlaySoundFrontend(char* sound_dict, char* sound_name)
{
	PLAY_SOUND_FRONTEND(-1, sound_name, sound_dict, 0);
}
void PlaySoundFrontend_default(char* sound_name)
{
	PLAY_SOUND_FRONTEND(-1, sound_name, "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
}
bool Check_compare_string_length(char* unk1, size_t max_length)
{
	if (strlen(unk1) <= max_length) return true; else return false;
}
char* FloatToChar(float _float)
{
	memset(str, 0, sizeof(str));
	sprintf_s(str, sizeof(str), "%f", _float);
	return str;
}
float AddFloats(float float1, float float2)
{
}
char* AddStrings(char* string1, char* string2)
{
	/*memset(str, 0, sizeof(str));
	strcpy_s(str, "");
	strcpy_s(str, string1);
	strcat_s(str, string2);
	return str;*/
	std::string str1(string1);
	std::string str2(string2);
	str1.append(str2);
	return Convert::StringToChar(str1);
}
char* Add3Strings(char* string1, char* string2, char* string3)
{
	std::string str1(string1);
	std::string str2(string2);
	std::string str3(string3);
	str1.append(str2);
	str1.append(str3);
	return Convert::StringToChar(str1);
}
char* AddInt_S(char* string1, int int2)
{
	static char* Return;
	printf(Return, "%i", int2);
	Return = AddStrings(string1, Return);
	return Return;

	/*std::string string2 = string1;
	string2 += std::to_string(int2);

	char * Char = new char[string2.size() + 1];
	std::copy(string2.begin(), string2.end(), Char);
	Char[string2.size()] = '\0';

	static char* Return = Char;
	delete[] Char;
	return Return;*/
}
char* keyboard()
{
	float i = 2.0000f;
	while (i > 0.4750f)
	{
		WAIT(10);
		DRAW_RECT(i, 0.9389f, 0.3875f, 0.736f, titlebox.R, titlebox.G, titlebox.B, 120);
		i -= 0.0050f;
	}

	static char* tempChar;
	bool j;
	if (Check_self_in_vehicle()) j = true; else j = false;

	while (!IsKeyDown(VK_RETURN))
	{
		WAIT(5);
		DRAW_RECT(i, 0.9389f, 0.3875f, 0.736f, titlebox.R, titlebox.G, titlebox.B, 120);
		setupdraw();
		SET_TEXT_FONT(1);
		drawstring("INPUT:", 0.2836f, 0.9129f);


		if (IsKeyJustUp('1')) AddStrings(tempChar, "1");
		else if (IsKeyJustUp('2')) AddStrings(tempChar, "2");
		else if (IsKeyJustUp('3')) AddStrings(tempChar, "3");
		else if (IsKeyJustUp('4')) AddStrings(tempChar, "4");
		else if (IsKeyJustUp('5')) AddStrings(tempChar, "5");
		else if (IsKeyJustUp('6')) AddStrings(tempChar, "6");
		else if (IsKeyJustUp('7')) AddStrings(tempChar, "7");
		else if (IsKeyJustUp('8')) AddStrings(tempChar, "8");
		else if (IsKeyJustUp('9')) AddStrings(tempChar, "9");
		else if (IsKeyJustUp('0')) AddStrings(tempChar, "0");
		else if (IsKeyJustUp('A')) AddStrings(tempChar, "A");
		else if (IsKeyJustUp('B')) AddStrings(tempChar, "B");
		else if (IsKeyJustUp('C')) AddStrings(tempChar, "C");
		else if (IsKeyJustUp('D')) AddStrings(tempChar, "D");
		else if (IsKeyJustUp('E')) AddStrings(tempChar, "E");
		else if (IsKeyJustUp('F')){ AddStrings(tempChar, "F"); if (j) SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), myVeh, FindFreeCarSeat(myVeh)); }
		else if (IsKeyJustUp('G')) AddStrings(tempChar, "G");
		else if (IsKeyJustUp('H')) AddStrings(tempChar, "H");
		else if (IsKeyJustUp('I')) AddStrings(tempChar, "I");
		else if (IsKeyJustUp('J')) AddStrings(tempChar, "J");
		else if (IsKeyJustUp('K')) AddStrings(tempChar, "K");
		else if (IsKeyJustUp('L')) AddStrings(tempChar, "L");
		else if (IsKeyJustUp('M')) AddStrings(tempChar, "M");
		else if (IsKeyJustUp('N')) AddStrings(tempChar, "N");
		else if (IsKeyJustUp('O')) AddStrings(tempChar, "O");
		else if (IsKeyJustUp('P')) AddStrings(tempChar, "P");
		else if (IsKeyJustUp('Q')) AddStrings(tempChar, "Q");
		else if (IsKeyJustUp('R')) AddStrings(tempChar, "R");
		else if (IsKeyJustUp('S')) AddStrings(tempChar, "S");
		else if (IsKeyJustUp('T')) AddStrings(tempChar, "T");
		else if (IsKeyJustUp('U')) AddStrings(tempChar, "U");
		else if (IsKeyJustUp('V')) AddStrings(tempChar, "V");
		else if (IsKeyJustUp('W')) AddStrings(tempChar, "W");
		else if (IsKeyJustUp('X')) AddStrings(tempChar, "X");
		else if (IsKeyJustUp('Y')) AddStrings(tempChar, "Y");
		else if (IsKeyJustUp('Z')) AddStrings(tempChar, "Z");
		else if (IsKeyJustUp(VK_ESCAPE)) return "";
		else if (IsKeyJustUp(VK_SPACE)) AddStrings(tempChar, " ");
		else if (IsKeyJustUp(VK_BACK) && strlen(tempChar) > 0)
		{ 
			std::string tempStr(tempChar); tempStr.pop_back();
			char *tempChar2 = new char[tempStr.length() + 1];
			std::strcpy(tempChar2, tempStr.c_str());
			tempChar = tempChar2;
			delete[] tempChar2;
		}

		setupdraw();
		SET_TEXT_FONT(14);
		SET_TEXT_CENTRE(1);
		drawstring(tempChar, 0.46, 0.9);

	}
	return tempChar;
}
int StringToInt(char* text)
{
	static int tempp;
	if (text == "") return NULL;
	if (STRING_TO_INT(text, &tempp)) return NULL;

	return tempp;
}
Hash $(char* value)
{
	return GET_HASH_KEY(value);
}
void DrawModSelected()
{
	if (OptionY < 0.6325 && OptionY > 0.1425) DRAW_SPRITE("commonmenu", "shop_garage_icon_b", 0.233f + menuPos, 0.015f + OptionY, 0.036f, 0.036f, 0.0f, 255, 255, 255, 255);
}
void PrintStringBottomCentre(char* text)
{
	_0xB87A37EEB7FAA67D("STRING");
	_ADD_TEXT_COMPONENT_STRING(text);
	_0x9D77056A530643F6(2000, 1);
}
void PrintFloatBottomCentre(float text, __int8 decimal_places)
{
	_0xB87A37EEB7FAA67D("NUMBER");
	ADD_TEXT_COMPONENT_FLOAT(text, (DWORD)decimal_places);
	_0x9D77056A530643F6(2000, 1);
}
void PrintIntBottomCentre(float text)
{
	_0xB87A37EEB7FAA67D("NUMBER");
	ADD_TEXT_COMPONENT_INTEGER(text);
	_0x9D77056A530643F6(2000, 1);
}
void PrintBottomLeft(char* text)
{
	_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	_ADD_TEXT_COMPONENT_STRING(text);
	_DRAW_NOTIFICATION(0, 1);
}
void DrawDebugConsole()
{
	SET_TEXT_FONT(0);
	SET_TEXT_SCALE(0, 0.5);
	SET_TEXT_CENTRE(0);
	for (int i = 0; i < 5; i++)
	{
		if (DebugTexts[i] != "")
		{
			SET_TEXT_FONT(0);
			SET_TEXT_SCALE(0, 0.3);
			SET_TEXT_CENTRE(0);
			drawstring(DebugTexts[i], 0.7725, DebugPos[i]);
		}
	}
}
void PrintDebugMessage(char* text)
{
	if (!DebugMode) return;
	int DebugI = DebugTextsPrinted;
	if (DebugTextsPrinted > 4)
	{
		DebugI = 4;
		for (int i = 0; i < 5; i++)
		{
			DebugTexts[i] = DebugTexts[i + 1];
		}
	}
	DebugTexts[DebugI] = text;
	DebugTextsPrinted++;
}
bool CompareMemory(const uint8_t* pData, const uint8_t* bMask, const char* sMask)
{
	for (; *sMask; ++sMask, ++pData, ++bMask)
		if (*sMask == 'x' && *pData != *bMask)
			return false;

	return *sMask == NULL;
}
intptr_t FindPattern(const char* bMask, const char* sMask)
{
	// Game Base & Size
	static intptr_t pGameBase = (intptr_t)GetModuleHandle(nullptr);
	static uint32_t pGameSize = 0;
	if (!pGameSize)
	{
		MODULEINFO info;
		GetModuleInformation(GetCurrentProcess(), (HMODULE)pGameBase, &info, sizeof(MODULEINFO));
		pGameSize = info.SizeOfImage;
	}

	// Scan
	for (uint32_t i = 0; i < pGameSize; i++)
		if (CompareMemory((uint8_t*)(pGameBase + i), (uint8_t*)bMask, sMask))
			return pGameBase + i;

	return 0;
}
void EnableTracks(bool tracksVehicle = false, bool tracksPeds = false, bool deepTracksVehicle = false, bool deepTracksPed = false)
{
	static auto VAR_FeetSnowTracks_call = FindPattern("\x80\x3D\x00\x00\x00\x00\x00\x48\x8B\xD9\x74\x37", "xx?????xxxxx");
	if (!VAR_FeetSnowTracks_call)
	{
		PrintDebugMessage("Snow Mod is ~r~not compatible ~s~with this GTA Version #1!");
		return;
	}
	static auto VAR_FeetSnowTracks = VAR_FeetSnowTracks_call + (*(int32_t *)(VAR_FeetSnowTracks_call + 2)) + 7;
	//
	static auto VAR_VehicleSnowTracks_call = FindPattern("\x40\x38\x3D\x00\x00\x00\x00\x48\x8B\x42\x20", "xxx????xxxx");
	if (!VAR_VehicleSnowTracks_call)
	{
		PrintDebugMessage("Snow Mod is ~r~not compatible ~s~with this GTA Version #2!");
		return;
	}
	static auto VAR_VehicleSnowTracks = VAR_VehicleSnowTracks_call + (*(int32_t *)(VAR_VehicleSnowTracks_call + 3)) + 7;
	//

	VirtualProtect((void*)VAR_FeetSnowTracks, 1, PAGE_EXECUTE_READWRITE, nullptr);
	VirtualProtect((void*)VAR_VehicleSnowTracks, 1, PAGE_EXECUTE_READWRITE, nullptr);

	// Enable/Disable Vehicle/Foot Snow tracks
	*(uint8_t *)VAR_FeetSnowTracks = tracksVehicle;
	*(uint8_t *)VAR_VehicleSnowTracks = tracksPeds;

	// Switch for big/small tracks
	static auto vehicleTrackTypes = FindPattern("\xB9\x00\x00\x00\x00\x84\xC0\x44\x0F\x44\xF1", "x????xxxxxx");
	if (!vehicleTrackTypes)
	{
		PrintDebugMessage("Snow Mod is ~r~not compatible ~s~with this GTA Version #3!");
		return;
	}

	VirtualProtect((void*)vehicleTrackTypes, 1, PAGE_EXECUTE_READWRITE, nullptr);
	*(uint8_t *)(vehicleTrackTypes + 1) = deepTracksVehicle ? 0x13 : 0x14;

	static auto pedTrackTypes = FindPattern("\xB9\x00\x00\x00\x00\x84\xC0\x0F\x44\xD9\x48\x8B\x4F\x30", "x????xxxxxxxxx");
	if (!pedTrackTypes)
	{
		PrintDebugMessage("Snow Mod is ~r~not compatible ~s~with this GTA Version #4!");
		return;
	}
	VirtualProtect((void*)pedTrackTypes, 1, PAGE_EXECUTE_READWRITE, nullptr);
	*(uint8_t *)(pedTrackTypes + 1) = deepTracksPed ? 0x13 : 0x14;
}
void EnableSnow(bool bEnable)
{
	if (bEnable)
		EnableTracks(1, 1, 1, 1);
	else
		EnableTracks();

	// Adresses
	static auto addr1 = FindPattern("\x40\x38\x35\x00\x00\x00\x00\x74\x18\x84\xDB\x74\x14", "xxx????xxxxxx");
	static auto addr2 = FindPattern("\x44\x38\x3D\x00\x00\x00\x00\x74\x0F", "xxx????xx");

	PrintDebugMessage(AddStrings("addr1: ", Convert::ToString(addr1)));
	PrintDebugMessage(AddStrings("addr2: ", Convert::ToString(addr2)));

	// Outdated
	// In future the patterns might change
	if (!addr1 || !addr2)
	{
		PrintDebugMessage("Snow Mod is ~r~not compatible ~s~with this GTA Version #5!");
		return;
	}

	// Original Memory
	static uint8_t original1[14] = { 0 };
	static uint8_t original2[15] = { 0 };

	// Initialize
	static bool bInitialized = false;
	if (!bInitialized)
	{
		bInitialized = true;

		// Unprotect Memory
		VirtualProtect((void*)addr1, 13, PAGE_EXECUTE_READWRITE, nullptr);
		VirtualProtect((void*)addr2, 14, PAGE_EXECUTE_READWRITE, nullptr);

		// Copy original Memory
		memcpy(&original1, (void*)addr1, 13);
		memcpy(&original2, (void*)addr2, 14);
	}

	// Toggle
	if (bEnable)
	{
		// Weather

		// NOP checks
		memset((void*)addr1, 0x90, 13);
		memset((void*)addr2, 0x90, 14);

		// Notification
		PrintDebugMessage("Snow ~g~ON");
	}
	else
	{
		// Copy original memory
		memcpy((void*)addr1, &original1, 13);
		memcpy((void*)addr2, &original2, 14);

		// Weather

		// Notification
		PrintDebugMessage("Snow ~r~OFF");
	}
}
void PrintError_InvalidInput()
{
	PrintStringBottomCentre("~r~Error:~s~ Invalid Input.");
}
class menu
{
public:
	static unsigned __int16 currentsub;
	static unsigned __int16 currentop;
	static unsigned __int16 currentop_w_breaks;
	static unsigned __int16 totalop;
	static unsigned __int16 printingop;
	static unsigned __int16 breakcount;
	static unsigned __int16 totalbreaks;
	static unsigned __int8 breakscroll;
	static __int16 currentsub_ar_index;
	static int currentsub_ar[20];
	static int currentop_ar[20];
	static int SetSub_delayed;
	static unsigned long int livetimer;
	static bool bit_centre_title, bit_centre_options, bit_centre_breaks;
	static void loops();
	static void sub_handler();
	static void submenu_switch();
	static void DisableControls()
	{
		HIDE_HELP_TEXT_THIS_FRAME();
		SET_CINEMATIC_BUTTON_ACTIVE(1);
		DISABLE_CONTROL_ACTION(0, INPUT_NEXT_CAMERA, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_VEH_SELECT_NEXT_WEAPON, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_VEH_CIN_CAM, controllerinput_bool);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_X);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_ACCEPT);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_CANCEL);
		DISABLE_CONTROL_ACTION(0, INPUT_HUD_SPECIAL, controllerinput_bool);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_DOWN);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_UP);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_ACCEPT, controllerinput_bool);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_CANCEL, controllerinput_bool);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_LEFT, controllerinput_bool);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_RIGHT, controllerinput_bool);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_DOWN, controllerinput_bool);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_UP, controllerinput_bool);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_RDOWN, controllerinput_bool);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_ACCEPT, controllerinput_bool);
		HIDE_HUD_COMPONENT_THIS_FRAME(10);
		HIDE_HUD_COMPONENT_THIS_FRAME(6);
		HIDE_HUD_COMPONENT_THIS_FRAME(7);
		HIDE_HUD_COMPONENT_THIS_FRAME(9);
		HIDE_HUD_COMPONENT_THIS_FRAME(8);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_LEFT);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_RIGHT);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_WEAPON, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_WEAPON_UNARMED, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_WEAPON_MELEE, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_WEAPON_HANDGUN, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_WEAPON_SHOTGUN, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_WEAPON_SMG, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_WEAPON_AUTO_RIFLE, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_WEAPON_SNIPER, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_WEAPON_HEAVY, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_WEAPON_SPECIAL, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_WEAPON_WHEEL_NEXT, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_WEAPON_WHEEL_PREV, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_WEAPON_SPECIAL_TWO, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_DIVE, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_MELEE_ATTACK_LIGHT, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_MELEE_ATTACK_HEAVY, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_MELEE_BLOCK, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_ARREST, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_VEH_HEADLIGHT, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_VEH_RADIO_WHEEL, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_CONTEXT, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_RELOAD, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_DIVE, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_VEH_CIN_CAM, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_JUMP, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_VEH_SELECT_NEXT_WEAPON, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_VEH_FLY_SELECT_NEXT_WEAPON, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_CHARACTER_FRANKLIN, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_CHARACTER_MICHAEL, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_CHARACTER_TREVOR, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_CHARACTER_MULTIPLAYER, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_CHARACTER_WHEEL, controllerinput_bool);
	}
	static void base()
	{
		GET_SCREEN_RESOLUTION(&screen_res_x, &screen_res_y); // Get screen res
		if (menu::currentsub != SUB::CLOSED)
		{
			char* dword = ("CommonMenu");
			if (!HAS_STREAMED_TEXTURE_DICT_LOADED(dword)){ REQUEST_STREAMED_TEXTURE_DICT(dword, 0); }
			background();
			optionhi();
		}
	}
	static void background()
	{
		float temp;
		if (totalop > 14) temp = 14; else temp = (float)totalop; // Calculate last option number to draw rect

		// Calculate Y Coord
		float bg_Y = ((temp * 0.035f) / 2.0f) + 0.159f;
		float bg_length = temp * 0.035f;

		// Draw titlebox
		if (gradients) DRAW_SPRITE("commonmenu", "interaction_bgd", 0.16f + menuPos, 0.1175f, menuScaleX + 0.20f, menuScaleY + 0.083f, 0.5, titlebox.R, titlebox.G, titlebox.B, titlebox.A);
		else DRAW_RECT(0.16f + menuPos, 0.1175f, menuScaleX + 0.20f, menuScaleY + 0.083f, titlebox.R, titlebox.G, titlebox.B, titlebox.A);

		// Draw background
		if (gradients) DRAW_SPRITE("commonmenu", "gradient_bgd", 0.16f + menuPos, bg_Y, menuScaleX + 0.20f, menuScaleY + bg_length, 0.5, BG.R, BG.G, BG.B, BG.A);
		else DRAW_RECT(0.16f + menuPos, bg_Y, menuScaleX + 0.20f, menuScaleY + bg_length, BG.R, BG.G, BG.B, BG.A);

		// Draw scroller indicator rect
		if (totalop > 14) temp = 14.0f; else temp = (float)totalop;
		float scr_rect_Y = ((temp + 1.0f) * 0.035f) + 0.1415f;
		if (gradients) DRAW_SPRITE("commonmenu", "gradient_bgd", 0.16f + menuPos, scr_rect_Y, menuScaleX + 0.20f, menuScaleY + 0.0345f, 0.5, BG.R, BG.G, BG.B, BG.A);
		else DRAW_RECT(0.16f + menuPos, scr_rect_Y, menuScaleX + 0.20f, menuScaleY + 0.0345f, BG.R, BG.G, BG.B, BG.A);

		// Draw thin line over scroller indicator rect
		if (totalop < 14) DRAW_RECT(0.16f + menuPos, (float)(totalop)* 0.035f + 0.16f, menuScaleX + 0.20f, menuScaleY + 0.0022f, 255, 255, 255, 255);
		else DRAW_RECT(0.16f + menuPos, 14.0f * 0.035f + 0.16f, menuScaleX + 0.20f, menuScaleY + 0.0022f, 255, 255, 255, 255);

		// Draw scroller indicator
		char* dword = ("CommonMenu");
		if ((totalop > 14) && HAS_STREAMED_TEXTURE_DICT_LOADED(dword))
		{
			char* dword2 = "shop_arrows_upANDdown";
			char* dword3 = "arrowright";
			Vector3 texture_res = GET_TEXTURE_RESOLUTION(dword, dword2);

			temp = ((14.0f + 1.0f) * 0.035f) + 0.1259f;

			if (currentop == 1)	DRAW_SPRITE(dword, dword3, 0.16f + menuPos, temp + 0.009, menuScaleX + 0.03f, menuScaleY + 0.03f, 270.0f, titlebox.R, titlebox.G, titlebox.B, 255);
			else if (currentop == totalop) DRAW_SPRITE(dword, dword3, 0.16f + menuPos, temp + 0.009, 0.03f, menuScaleX + 0.03f, menuScaleY + 90.0f, titlebox.R, titlebox.G, titlebox.B, 255);
			else DRAW_SPRITE(dword, dword2, 0.16f + menuPos, temp + 0.012, menuScaleX + 0.035f, menuScaleY + 0.035f, 0.0f, titlebox.R, titlebox.G, titlebox.B, 255);

		}

		// Draw option count
		temp = scr_rect_Y - 0.0124f;
		setupdraw();
		SET_TEXT_FONT(0);
		SET_TEXT_SCALE(menuScaleX + 0.0f, menuScaleY + 0.26f);
		SET_TEXT_COLOUR(optioncount.R, optioncount.G, optioncount.B, optioncount.A);

		_SET_TEXT_ENTRY("CM_ITEM_COUNT");
		ADD_TEXT_COMPONENT_INTEGER(currentop); // ! currentop_w_breaks
		ADD_TEXT_COMPONENT_INTEGER(totalop); // ! totalop - totalbreaks
		_DRAW_TEXT(0.2205f + menuPos, temp);
	}
	static void optionhi()
	{
		float Y_coord;
		if (currentop > 14) Y_coord = 14.0f; else Y_coord = (float)currentop;

		Y_coord = (Y_coord * 0.035f) + 0.1415f;
		if (gradients) DRAW_SPRITE("commonmenu", "gradient_nav", 0.16f + menuPos, Y_coord, menuScaleX + 0.20f, menuScaleY + 0.035f, 0.5, selectionhi.R, selectionhi.G, selectionhi.B, selectionhi.A);
		else DRAW_RECT(0.16f + menuPos, Y_coord, menuScaleX + 0.20f, menuScaleY + 0.035f, selectionhi.R, selectionhi.G, selectionhi.B, selectionhi.A);
	}
	static bool isBinds()
	{
		// Open menu - RB + LB / NUM4 + NUM6
		return ((IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_RB) && IS_DISABLED_CONTROL_PRESSED(2, INPUT_SCRIPT_PAD_DOWN)) || (IsKeyDown(VK_F5)));
	}
	static void while_closed()
	{
		if (isBinds())
		{
			PlaySoundFrontend("FocusIn", "HintCamSounds");
			currentsub = 1;
			currentsub_ar_index = 0;
			currentop = 1;
		}
	}
	static void while_opened()
	{
		totalop = printingop; printingop = 0;
		totalbreaks = breakcount; breakcount = 0; breakscroll = 0;

		if (IS_PAUSE_MENU_ACTIVE()) SetSub_closed();

		DISPLAY_AMMO_THIS_FRAME(0);
		DISPLAY_CASH(0);
		SET_RADAR_ZOOM(0);

		DisableControls();
		if (!DisplayKeyboard)
		{
			// Scroll up
			if (!IsKeyDown(0x57) && IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_SCRIPT_PAD_UP) || IsKeyJustUp(VK_NUMPAD8))
			{
				if (currentop == 1) Bottom(); else Up();
			}

			// Scroll down
			if (!IsKeyDown(0x53) && IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_SCRIPT_PAD_DOWN) || IsKeyJustUp(VK_NUMPAD2))
			{
				if (currentop == totalop) Top(); else Down();
			}

			// B press
			if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_SCRIPT_RRIGHT) || IsKeyJustUp(VK_NUMPAD0) || IsKeyJustUp(VK_BACK))
			{
				if (currentsub == SUB::MAINMENU) SetSub_closed(); else SetSub_previous();
			}

			// Binds press
			if (currentsub != SUB::MAINMENU && isBinds())
			{
				SetSub_closed();
			}
		}
	}
	static void Up()
	{
		currentop--; currentop_w_breaks--;
		PlaySoundFrontend_default("NAV_UP_DOWN");
		breakscroll = 1;
	}
	static void Down()
	{
		currentop++; currentop_w_breaks++;
		PlaySoundFrontend_default("NAV_UP_DOWN");
		breakscroll = 2;
	}
	static void Bottom()
	{
		currentop = totalop; currentop_w_breaks = totalop;
		PlaySoundFrontend_default("NAV_UP_DOWN");
		breakscroll = 3;
	}
	static void Top()
	{
		currentop = 1; currentop_w_breaks = 1;
		PlaySoundFrontend_default("NAV_UP_DOWN");
		breakscroll = 4;
	}
	static void SetSub_previous()
	{
		currentsub = currentsub_ar[currentsub_ar_index]; // Get previous submenu from array and set as current submenu
		currentop = currentop_ar[currentsub_ar_index]; // Get last selected option from array and set as current selected option
		currentsub_ar_index--; // Decrement array index by 1
		printingop = 0; // Reset option print variable
		PlaySoundFrontend_default("BACK"); // Play sound
	}
	static void SetSub_new(int sub_index)
	{
		currentsub_ar_index++; // Increment array index
		currentsub_ar[currentsub_ar_index] = currentsub; // Store current submenu index in array
		currentsub = sub_index; // Set new submenu as current submenu (Static_1)

		currentop_ar[currentsub_ar_index] = currentop; // Store currently selected option in array
		currentop = 1; currentop_w_breaks = 1; // Set new selected option as first option in submenu

		printingop = 0; // Reset currently printing option var
	}
	static void SetSubNewLoop()
	{
		if (SubmenuSwithState == 1)
		{
			titlebox.A -= 25;
			BG.A -= 25;
			titletext.A -= 25;
			optiontext.A -= 25;
			optioncount.A -= 25;
			selectedtext.A -= 25;
			optionbreaks.A -= 25;
			selectionhi.A -= 25;
			menuScaleX += 0.005;
			menuScaleY += 0.005;
			if (menuScaleX <= 0.1) SubmenuSwithState = 2;
		}
		if (SubmenuSwithState == 2)
		{
			currentsub_ar_index++; // Increment array index
			currentsub_ar[currentsub_ar_index] = currentsub; // Store current submenu index in array
			currentsub = _subindex; // Set new submenu as current submenu (Static_1)

			currentop_ar[currentsub_ar_index] = currentop; // Store currently selected option in array
			currentop = 1; currentop_w_breaks = 1; // Set new selected option as first option in submenu

			printingop = 0; // Reset currently printing option var
			SubmenuSwithState = 3;
			menuScaleX = -0.1;
			menuScaleY = -0.1;
		}
		if (SubmenuSwithState == 3)
		{
			titlebox.A += 25;
			BG.A += 25;
			titletext.A += 25;
			optiontext.A += 25;
			optioncount.A += 25;
			selectedtext.A += 25;
			optionbreaks.A += 25;
			selectionhi.A += 25;
			menuScaleX += 0.005;
			menuScaleY += 0.005;
			if (menuScaleX <= 0){ SubmenuSwithState = 0; SwitchingSubmenu = 0; }
		}


	}
	static void SetSub_closed()
	{
		ENABLE_ALL_CONTROL_ACTIONS(2);
		PlaySoundFrontend_default("BACK");
		currentsub = SUB::CLOSED;
	}

}; unsigned __int16 menu::currentsub = 0; unsigned __int16 menu::currentop = 0; unsigned __int16 menu::currentop_w_breaks = 0; unsigned __int16 menu::totalop = 0; unsigned __int16 menu::printingop = 0; unsigned __int16 menu::breakcount = 0; unsigned __int16 menu::totalbreaks = 0; unsigned __int8 menu::breakscroll = 0; __int16 menu::currentsub_ar_index = 0; int menu::currentsub_ar[20] = {}; int menu::currentop_ar[20] = {}; int menu::SetSub_delayed = 0; unsigned long int menu::livetimer; bool menu::bit_centre_title = 1, menu::bit_centre_options = 0, menu::bit_centre_breaks = 1;
bool CheckAJPressed()
{
	if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_SCRIPT_RDOWN) || IsKeyJustUp(VK_NUMPAD5) || IsKeyJustUp(VK_RETURN)) return true; else return false;
}
bool CheckRPressed()
{
	if (IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_RIGHT) || IsKeyDown(VK_NUMPAD6)) return true; else return false;
}
bool CheckRJPressed()
{
	if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_RIGHT) || IsKeyJustUp(VK_NUMPAD6)) return true; else return false;
}
bool CheckLPressed()
{
	if (IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_LEFT) || IsKeyDown(VK_NUMPAD4)) return true; else return false;
}
bool CheckLJPressed()
{
	if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_LEFT) || IsKeyJustUp(VK_NUMPAD4)) return true; else return false;
}
bool IsOptionPressed()
{
	if (CheckAJPressed())
	{
		PlaySoundFrontend_default("SELECT");
		return true;
	}
	else return false;
}
bool IsOptionRPressed()
{
	if (CheckRPressed())
	{
		PlaySoundFrontend_default("NAV_LEFT_RIGHT");
		return true;
	}
	else return false;
}
bool IsOptionRJPressed()
{
	if (CheckRJPressed())
	{
		PlaySoundFrontend_default("NAV_LEFT_RIGHT");
		return true;
	}
	else return false;
}
bool IsOptionLPressed()
{
	if (CheckLPressed())
	{
		PlaySoundFrontend_default("NAV_LEFT_RIGHT");
		return true;
	}
	else return false;
}
bool IsOptionLJPressed()
{
	if (CheckLJPressed())
	{
		PlaySoundFrontend_default("NAV_LEFT_RIGHT");
		return true;
	}
	else return false;
}
void AddTitle(char* text)
{
	setupdraw();
	SET_TEXT_FONT(font_title);

	SET_TEXT_COLOUR(titletext.R, titletext.G, titletext.B, titletext.A);

	if (menu::bit_centre_title)
	{
		SET_TEXT_CENTRE(1);
		OptionY = 0.16f + menuPos; // X coord
	}
	else OptionY = 0.066f + menuPos; // X coord

	if (Check_compare_string_length(text, 14))
	{
		SET_TEXT_SCALE(menuScaleX + 0.75f, menuScaleY + 0.75f);
		drawstring(text, OptionY, 0.1f);
	}
	else drawstring(text, OptionY, 0.13f);

}
void nullFunc(){ return; }
void AddOption(char* text, bool &option_code_bool = null, void (&Func)() = nullFunc, int submenu_index = -1)
{
	char* tempChar;
	if (font_options == 2 || font_options == 7) tempChar = "  ------"; // Font unsafe
	else tempChar = "  ~b~>"; // Font safe

	if (menu::printingop + 1 == menu::currentop && (font_selection == 2 || font_selection == 7)) tempChar = "  ------"; // Font unsafe
	else tempChar = "  ~b~>"; // Font safe

	menu::printingop++;

	OptionY = 0.0f;
	if (menu::currentop <= 14)
	{
		if (menu::printingop > 14) return;
		else OptionY = ((float)(menu::printingop) * 0.035f) + 0.125f;
	}
	else
	{
		if (menu::printingop < (menu::currentop - 13) || menu::printingop > menu::currentop) return;
		else OptionY = ((float)(menu::printingop - (menu::currentop - 14))* 0.035f) + 0.125f;
	}

	setupdraw();
	SET_TEXT_FONT(font_options);
	SET_TEXT_COLOUR(optiontext.R, optiontext.G, optiontext.B, optiontext.A);
	if (menu::printingop == menu::currentop)
	{
		SET_TEXT_FONT(font_selection);
		SET_TEXT_COLOUR(selectedtext.R, selectedtext.G, selectedtext.B, selectedtext.A);
		if (IsOptionPressed())
		{
			/*if (&option_code_bool != &null)*/ option_code_bool = true;
			Func();
			if (submenu_index != -1) menu::SetSub_delayed = submenu_index;
		}
	}

	if (submenu_index != -1) text = AddStrings(text, tempChar);
	if (menu::bit_centre_options)
	{
		SET_TEXT_CENTRE(1);
		drawstring(text, 0.16f + menuPos, OptionY);
	}
	else drawstring(text, 0.066f + menuPos, OptionY);
}
void OptionStatus(int status)
{
	if (OptionY < 0.6325f && OptionY > 0.1425f)
	{
		char* tempChar;
		SET_TEXT_FONT(4);
		SET_TEXT_SCALE(menuScaleX + 0.34f, menuScaleY + 0.34f);
		SET_TEXT_CENTRE(1);

		if (status == 0){
			SET_TEXT_COLOUR(255, 102, 102, 250); //RED
			tempChar = "OFF";
		}
		else if (status == 1){
			SET_TEXT_COLOUR(102, 255, 102, 250); //GREEN
			tempChar = "ON";
		}
		else{
			SET_TEXT_COLOUR(255, 255, 102, 250); //YELLOW
			tempChar = "??";
		}

		drawstring(tempChar, 0.233f + menuPos, OptionY);

	}
}
void AddToggle(char* text, bool &loop_variable, bool &extra_option_code_ON = null, bool &extra_option_code_OFF = null)
{
	null = 0;
	AddOption(text, null);

	if (null){
			loop_variable = !loop_variable;
			if (loop_variable != 0) extra_option_code_ON = true;
			else extra_option_code_OFF = true;
		}

	OptionStatus((int)loop_variable); // Display ON/OFF
}
void AddCheck(char* text, bool &loop_variable, bool &extra_option_code_ON = null, bool &extra_option_code_OFF = null)
{
	null = 0;
	AddOption(text, null);
	if (loop_variable)
	{
		if (OptionY < 0.6325 && OptionY > 0.1425){ DRAW_SPRITE("commonmenu", "shop_tick_icon", 0.233f + menuPos, 0.015f + OptionY, 0.036f, 0.036f, 0.0f, 255, 255, 255, 255); }
	}
	if (null){
		loop_variable = !loop_variable;
		if (loop_variable != 0) extra_option_code_ON = true;
		else extra_option_code_OFF = true;
	}

}
void AddLocal(char* text, Void condition, bool &option_code_ON, bool &option_code_OFF)
{
	null = 0;
	AddOption(text, null);
	if (null)
	{ if (condition == 0) option_code_ON = true; else option_code_OFF = true; }
	
	if (condition == 0) OptionStatus(0); // Display OFF
	else				OptionStatus(1); // Display ON
}
void AddBreak(char* text)
{
	menu::printingop++; menu::breakcount++; 

	OptionY = 0.0f;
	if (menu::currentop <= 14)
	{
		if (menu::printingop > 14) return;
		else OptionY = ((float)(menu::printingop) * 0.035f) + 0.125f;
	}
	else
	{
		if (menu::printingop < (menu::currentop - 13) || menu::printingop > menu::currentop) return;
		else OptionY = ((float)(menu::printingop - (menu::currentop - 14))* 0.035f) + 0.125f;
	}

	setupdraw();
	SET_TEXT_FONT(font_breaks);
	SET_TEXT_COLOUR(optionbreaks.R, optionbreaks.G, optionbreaks.B, optionbreaks.A);
	if (menu::printingop == menu::currentop)
	{
		switch (menu::breakscroll)
		{
		case 1:
			menu::currentop_w_breaks = menu::currentop_w_breaks + 1;
			menu::currentop--; break;
		case 2:
			menu::currentop_w_breaks = menu::currentop - menu::breakcount;
			menu::currentop++; break;
		case 3:
			menu::currentop_w_breaks = menu::totalop - (menu::totalbreaks - 1);
			menu::currentop--; break;
		case 4:
			menu::currentop_w_breaks = 1;
			menu::currentop++; break;
		}
		
	}
	if (menu::bit_centre_breaks)
	{
		SET_TEXT_CENTRE(1);
		drawstring(text, 0.16f + menuPos, OptionY);
	}
	else
	{
		drawstring(text, 0.066f + menuPos, OptionY);
	}

}
void AddNumber(char* text, long value, __int8 decimal_places, bool &A_PRESS = null, bool &RIGHT_PRESS = null, bool &LEFT_PRESS = null)
{
	null = 0;
	AddOption(text, null);

	if (OptionY < 0.6325 && OptionY > 0.1425)
	{
		SET_TEXT_FONT(0);
		SET_TEXT_SCALE(0.26f, 0.26f);
		SET_TEXT_CENTRE(1);

		drawfloat(value, (DWORD)decimal_places, 0.233f + menuPos, OptionY);
	}

	if (menu::printingop == menu::currentop)
	{
		if (null) A_PRESS = true;
		else if (IsOptionRJPressed()) RIGHT_PRESS = true;
		else if (IsOptionRPressed()) RIGHT_PRESS = true;
		else if (IsOptionLJPressed()) LEFT_PRESS = true;
		else if (IsOptionLPressed()) LEFT_PRESS = true;

	}

}
void AddNumber2(char* text, long value, __int8 decimal_places, bool &A_PRESS = null, bool &RIGHT_PRESS = null, bool &LEFT_PRESS = null)
{
	null = 0;
	AddOption(text, null);

	if (OptionY < 0.6325 && OptionY > 0.1425)
	{
		SET_TEXT_FONT(0);
		SET_TEXT_SCALE(0.26f, 0.26f);
		SET_TEXT_CENTRE(1);

		drawfloat(value, (DWORD)decimal_places, 0.233f + menuPos, OptionY);
	}

	if (menu::printingop == menu::currentop)
	{
		if (null) A_PRESS = true;
		else if (IS_DISABLED_CONTROL_JUST_RELEASED(2, INPUT_SCRIPT_PAD_RIGHT) || IsKeyJustUp(VK_NUMPAD6)) PlaySoundFrontend_default("NAV_LEFT_RIGHT"), RIGHT_PRESS = true;
		else if (IS_DISABLED_CONTROL_JUST_RELEASED(2, INPUT_SCRIPT_PAD_RIGHT) || IsKeyJustUp(VK_NUMPAD6)) PlaySoundFrontend_default("NAV_LEFT_RIGHT"), RIGHT_PRESS = true;
		else if (IS_DISABLED_CONTROL_JUST_RELEASED(2, INPUT_SCRIPT_PAD_LEFT) || IsKeyJustUp(VK_NUMPAD4)) PlaySoundFrontend_default("NAV_LEFT_RIGHT"), LEFT_PRESS = true;
		else if (IS_DISABLED_CONTROL_JUST_RELEASED(2, INPUT_SCRIPT_PAD_LEFT) || IsKeyJustUp(VK_NUMPAD4)) PlaySoundFrontend_default("NAV_LEFT_RIGHT"), LEFT_PRESS = true;

	}

}
void AddNumberSimple(char* text, int &value, int max = 100, int min = 0)
{
	DisplayKeyboard = 0;
	bool apress = 0, rpress = 0, lpress = 0;
	AddNumber(text, value, 0, apress, rpress, lpress);
	if (apress)
	{
		while (DisplayKeyboard)
		{
			if (!OnscreenKeyboardDisplayed){ DISPLAY_ONSCREEN_KEYBOARD(false, "", "", "", "", "", "", 100); OnscreenKeyboardDisplayed = 1; }
			switch (UPDATE_ONSCREEN_KEYBOARD())
			{
			case 1: WAIT(100); DisplayKeyboard = 0; OnscreenKeyboardDisplayed = 0; value = Convert::ToInt32(GET_ONSCREEN_KEYBOARD_RESULT()); if (value < min) value = min; if (value > max) value = max; break;
			case 2: DisplayKeyboard = 0; OnscreenKeyboardDisplayed = 0; PrintDebugMessage("Keyboard input ~r~canceled"); break;
			case 3: WAIT(100); DisplayKeyboard = 0; OnscreenKeyboardDisplayed = 0; PrintDebugMessage("~r~ ERROR: ~s~Unknown keyboard error"); break;
			default: break;
			}
			WAIT(0);
		}
	}
	if (lpress)
	{
		if (value == min){ value = max; return; }
		value--;
	}
	if (rpress)
	{
		if (value == max){ value = min; return; }
		value++;
	}
}
void AddNumberSimple2(char* text, int &value, int max = 100, int min = 0)
{
	DisplayKeyboard = 0;
	bool apress = 0, rpress = 0, lpress = 0;
	AddNumber2(text, value, 0, apress, rpress, lpress);
	if (apress)
	{
		while (DisplayKeyboard)
		{
			if (!OnscreenKeyboardDisplayed){ DISPLAY_ONSCREEN_KEYBOARD(false, "", "", "", "", "", "", 100); OnscreenKeyboardDisplayed = 1; }
			switch (UPDATE_ONSCREEN_KEYBOARD())
			{
			case 1: WAIT(100); DisplayKeyboard = 0; OnscreenKeyboardDisplayed = 0; value = Convert::ToInt32(GET_ONSCREEN_KEYBOARD_RESULT()); if (value < min) value = min; if (value > max) value = max; break;
			case 2: DisplayKeyboard = 0; OnscreenKeyboardDisplayed = 0; PrintDebugMessage("Keyboard input ~r~canceled"); break;
			case 3: WAIT(100); DisplayKeyboard = 0; OnscreenKeyboardDisplayed = 0; PrintDebugMessage("~r~ ERROR: ~s~Unknown keyboard error"); break;
			default: break;
			}
			WAIT(0);
		}
	}
	if (lpress)
	{
		if (value == min){ value = max; return; }
		value--;
	}
	if (rpress)
	{
		if (value == max){ value = min; return; }
		value++;
	}
}
void AddText(char* text, char* text_, __int8 decimal_places, bool &A_PRESS = null, bool &RIGHT_PRESS = null, bool &LEFT_PRESS = null)
{
	null = 0;
	AddOption(text, null);

	if (OptionY < 0.6325 && OptionY > 0.1425)
	{
		SET_TEXT_FONT(0);
		SET_TEXT_SCALE(0.26f, 0.26f);
		SET_TEXT_CENTRE(1);

		drawstring(AddStrings("~u~" ,text_), 0.218f + menuPos, OptionY);
	}

	if (menu::printingop == menu::currentop)
	{
		if (null) A_PRESS = true;
		else if (IS_DISABLED_CONTROL_JUST_RELEASED(2, INPUT_SCRIPT_PAD_RIGHT) || IsKeyJustUp(VK_NUMPAD6)) PlaySoundFrontend_default("NAV_LEFT_RIGHT"), RIGHT_PRESS = true;
		else if (IS_DISABLED_CONTROL_JUST_RELEASED(2, INPUT_SCRIPT_PAD_RIGHT) || IsKeyJustUp(VK_NUMPAD6)) PlaySoundFrontend_default("NAV_LEFT_RIGHT"), RIGHT_PRESS = true;
		else if (IS_DISABLED_CONTROL_JUST_RELEASED(2, INPUT_SCRIPT_PAD_LEFT) || IsKeyJustUp(VK_NUMPAD4)) PlaySoundFrontend_default("NAV_LEFT_RIGHT"), LEFT_PRESS = true;
		else if (IS_DISABLED_CONTROL_JUST_RELEASED(2, INPUT_SCRIPT_PAD_LEFT) || IsKeyJustUp(VK_NUMPAD4)) PlaySoundFrontend_default("NAV_LEFT_RIGHT"), LEFT_PRESS = true;

	}

}
void AddTextWithBlackListedWords(char* text, char* text_, __int8 decimal_places, bool &A_PRESS = null, bool &RIGHT_PRESS = null, bool &LEFT_PRESS = null)
{
	null = 0;
	AddOption(text, null);

	if (menu::printingop == menu::currentop)
	{
		if (null) A_PRESS = true;
		else if (IS_DISABLED_CONTROL_JUST_RELEASED(2, INPUT_SCRIPT_PAD_RIGHT) || IsKeyJustUp(VK_NUMPAD6)) PlaySoundFrontend_default("NAV_LEFT_RIGHT"), RIGHT_PRESS = true;
		else if (IS_DISABLED_CONTROL_JUST_RELEASED(2, INPUT_SCRIPT_PAD_RIGHT) || IsKeyJustUp(VK_NUMPAD6)) PlaySoundFrontend_default("NAV_LEFT_RIGHT"), RIGHT_PRESS = true;
		else if (IS_DISABLED_CONTROL_JUST_RELEASED(2, INPUT_SCRIPT_PAD_LEFT) || IsKeyJustUp(VK_NUMPAD4)) PlaySoundFrontend_default("NAV_LEFT_RIGHT"), LEFT_PRESS = true;
		else if (IS_DISABLED_CONTROL_JUST_RELEASED(2, INPUT_SCRIPT_PAD_LEFT) || IsKeyJustUp(VK_NUMPAD4)) PlaySoundFrontend_default("NAV_LEFT_RIGHT"), LEFT_PRESS = true;

	}

	switch (GET_HASH_KEY(text_))
	{
	case 0x3ADB3357: return; //null
	case 0xE149B5E8: return; //carnotfound
	}
	if (OptionY < 0.6325 && OptionY > 0.1425)
	{
		SET_TEXT_FONT(0);
		SET_TEXT_SCALE(0.26f, 0.26f);
		SET_TEXT_CENTRE(1);

		drawstring(AddStrings("~u~", text_), 0.218f + menuPos, OptionY);
	}

}
void AddProtectedSub(char* text, int sub, bool protection, bool &extraOptionCode = null)
{
	if (protection) AddOption(text, extraOptionCode, nullFunc, sub);
	else AddOption(AddStrings(text, "  ~b~>"));
}
void RequestAndDrawVehSprite(char* textures[], char* textureDict, char* vehModel, int i)
{
	if (textures[i] == vehModel){
		if (!HAS_STREAMED_TEXTURE_DICT_LOADED(textureDict)) REQUEST_STREAMED_TEXTURE_DICT(textureDict, true);
		DRAW_SPRITE(textureDict, vehModel, menuPos + 0.34, OptionY + 0.05, 0.15070635, 0.0963855, 0.0, 255, 255, 255, 255);
	}
}
void CreateVehicleHash(Hash model)
{
	Vector3 myPos = GET_ENTITY_COORDS(PLAYER_PED_ID(), 0);
	Vehicle Veh = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());
	float LastVehSpeed = 0;
	if (IS_MODEL_IN_CDIMAGE(model))
	{
		PrintDebugMessage(Add3Strings("Model ", Convert::ToString(model), "is in cdimage"));
		REQUEST_MODEL(model);
		PrintDebugMessage(AddStrings("Requesting model ", Convert::ToString(model)));
		while (!HAS_MODEL_LOADED(model)) WAIT(0);
		PrintDebugMessage("Model loaded");
		if (VSDeleteLast && IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), false)){ LastVehSpeed = GET_ENTITY_SPEED(myVeh);  SET_ENTITY_AS_MISSION_ENTITY(Veh, true, false); DELETE_VEHICLE(&Veh); }
		PrintDebugMessage("Createing vehicle");
		Vehicle veh = CREATE_VEHICLE(model, myPos.x, myPos.y, myPos.z, GET_ENTITY_HEADING(PLAYER_PED_ID()), true, 0);
		PrintDebugMessage("Vehicle created");
		PrintDebugMessage(AddStrings("Vehicle handle: ~b~", Convert::ToString(veh)));
		if (VSSpawnInside) SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), veh, -1);
		if (VSDeleteLast && VSSpawnInside){ SET_VEHICLE_ENGINE_ON(veh, 1, 1);  SET_VEHICLE_FORWARD_SPEED(veh, LastVehSpeed); }
		if (VSSpawnWithCustomPlate){
			SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, VSCustomPlateType); SET_VEHICLE_NUMBER_PLATE_TEXT(veh, CustomPlateText);
		}
		if (VSSpawnUpgaraded){
			SET_VEHICLE_MOD(veh, 11, 4, 0);
			SET_VEHICLE_MOD(veh, 12, 4, 0);
			SET_VEHICLE_MOD(veh, 13, 4, 0);
			SET_VEHICLE_MOD(veh, 15, 4, 0);
			SET_VEHICLE_MOD(veh, 16, 4, 1);
			TOGGLE_VEHICLE_MOD(veh, 18, 1);
		}
	}
	else
	{
		PrintBottomLeft(("~r~ERROR Invalid ~s~Model"));
	}

}
void AddVehicle(char* VehName, Hash VehModel)
{
	bool Spawn = 0;
	AddOption(_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(VehModel)), Spawn);
	if (menu::printingop == menu::currentop)
	{
		//DrawVehSprite(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(VehModel));
		if (Spawn)
		{
			CreateVehicleHash(VehModel);
		}
	}
}
void AddVehicleCustomName(char* VehName, Hash VehModel)
{
	bool Spawn = 0;
	AddOption(VehName, Spawn);
	if (menu::printingop == menu::currentop)
	{
		//DrawVehSprite(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(VehModel));
		if (Spawn)
		{
			CreateVehicleHash(VehModel);
		}
	}
}
void AddTele(char* text, float X, float Y, float Z, bool &extra_option_code = null)
{
	null = 0;
	AddOption(text, null);
	if (menu::printingop == menu::currentop)
	{
		if (null)
		{
			if (!Check_self_in_vehicle())
			{
				SET_ENTITY_COORDS(PLAYER_PED_ID(), X, Y, Z, 0, 0, 0, 1);
			}
			else
			{
				RequestControlOfEnt(myVeh);
				SET_ENTITY_COORDS(myVeh, X, Y, Z, 0, 0, 0, 1);
			}
			LOAD_ALL_OBJECTS_NOW();
			extra_option_code = true;
		}
	}

}
void AddKeyboard(char* text, bool &AfterKeyboardInput)
{
	AddOption(text, DisplayKeyboard);
	if (menu::printingop == menu::currentop)
	{
		while (DisplayKeyboard)
		{
			if (!OnscreenKeyboardDisplayed){ DISPLAY_ONSCREEN_KEYBOARD(false, "", "", "", "", "", "", 100); OnscreenKeyboardDisplayed = 1; }
			switch (UPDATE_ONSCREEN_KEYBOARD())
			{
			case 1: WAIT(100); DisplayKeyboard = 0; OnscreenKeyboardDisplayed = 0; AfterKeyboardInput = 1; break;
			case 2: DisplayKeyboard = 0; OnscreenKeyboardDisplayed = 0; PrintDebugMessage("Keyboard input ~r~canceled"); break;
			case 3: WAIT(100); DisplayKeyboard = 0; OnscreenKeyboardDisplayed = 0; PrintDebugMessage("~r~ ERROR: ~s~Unknown keyboard error"); break;
			default: break;
			}
			WAIT(0);
		}
	}
}
char* showKeyboard()
{
	DisplayKeyboard = true;
	while (DisplayKeyboard)
	{
		if (!OnscreenKeyboardDisplayed) { DISPLAY_ONSCREEN_KEYBOARD(false, "", "", "", "", "", "", 100); OnscreenKeyboardDisplayed = 1; }
		switch (UPDATE_ONSCREEN_KEYBOARD())
		{
		case 1: WAIT(100); DisplayKeyboard = 0; OnscreenKeyboardDisplayed = 0;  return GET_ONSCREEN_KEYBOARD_RESULT(); break;
		case 2: DisplayKeyboard = 0; OnscreenKeyboardDisplayed = 0; PrintDebugMessage("Keyboard input ~r~canceled"); break;
		case 3: WAIT(100); DisplayKeyboard = 0; OnscreenKeyboardDisplayed = 0; PrintDebugMessage("~r~ ERROR: ~s~Unknown keyboard error"); break;
		default: break;
		}
		WAIT(0);
	}

}
char* getFromArray(int a, int id)
{
	switch (a)
	{
	case Array::WeaponModels:
	{
		char* A[56] = { "WEAPON_KNIFE", "WEAPON_NIGHTSTICK", "WEAPON_HAMMER", "WEAPON_BAT", "WEAPON_GOLFCLUB", "WEAPON_CROWBAR", "WEAPON_PISTOL", "WEAPON_COMBATPISTOL", "WEAPON_APPISTOL", "WEAPON_PISTOL50", "WEAPON_MICROSMG", "WEAPON_SMG", "WEAPON_ASSAULTSMG", "WEAPON_ASSAULTRIFLE", "WEAPON_CARBINERIFLE", "WEAPON_ADVANCEDRIFLE", "WEAPON_MG", "WEAPON_COMBATMG", "WEAPON_PUMPSHOTGUN", "WEAPON_SAWNOFFSHOTGUN", "WEAPON_ASSAULTSHOTGUN", "WEAPON_BULLPUPSHOTGUN", "WEAPON_STUNGUN", "WEAPON_SNIPERRIFLE", "WEAPON_HEAVYSNIPER", "WEAPON_GRENADELAUNCHER", "WEAPON_GRENADELAUNCHER_SMOKE", "WEAPON_RPG", "WEAPON_MINIGUN", "WEAPON_GRENADE", "WEAPON_STICKYBOMB", "WEAPON_SMOKEGRENADE", "WEAPON_BZGAS", "WEAPON_MOLOTOV", "WEAPON_FIREEXTINGUISHER", "WEAPON_PETROLCAN", "WEAPON_SNSPISTOL", "WEAPON_SPECIALCARBINE", "WEAPON_HEAVYPISTOL", "WEAPON_BULLPUPRIFLE", "WEAPON_HOMINGLAUNCHER", "WEAPON_PROXMINE", "WEAPON_SNOWBALL", "WEAPON_VINTAGEPISTOL", "WEAPON_DAGGER", "WEAPON_FIREWORK", "WEAPON_MUSKET", "WEAPON_MARKSMANRIFLE", "WEAPON_HEAVYSHOTGUN", "WEAPON_GUSENBERG", "WEAPON_HATCHET", "WEAPON_RAILGUN", "WEAPON_COMBATPDW", "WEAPON_KNUCKLE", "WEAPON_MARKSMANPISTOL", "WEAPON_FLASHLIGHT" };
		if (id < 0)
		{
			if (id == -1)
			{
				return Convert::ToString(sizeof(A) / sizeof(A[0]));
			}
			else
			{
				PrintDebugMessage(Add3Strings("~r~ERROR: ~s~Array index out of range (", Convert::ToString(id), ") for WeaponModels"));
				return "NULL";
			}
		}
		return A[id];
	}
	case Array::allvehModels:
	{
		char* A[361] = { "NINEF", "NINEF2", "BLISTA", "ASEA", "ASEA2", "BOATTRAILER", "BUS", "ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "SUNTRAP", "COACH", "AIRBUS", "ASTEROPE", "AIRTUG", "AMBULANCE", "BARRACKS", "BARRACKS2", "BALLER", "BALLER2", "BJXL", "BANSHEE", "BENSON", "BFINJECTION", "BIFF", "BLAZER", "BLAZER2", "BLAZER3", "BISON", "BISON2", "BISON3", "BOXVILLE", "BOXVILLE2", "BOXVILLE3", "BOBCATXL", "BODHI2", "BUCCANEER", "BUFFALO", "BUFFALO2", "BULLDOZER", "BULLET", "BLIMP", "BURRITO", "BURRITO2", "BURRITO3", "BURRITO4", "BURRITO5", "CAVALCADE", "CAVALCADE2", "POLICET", "GBURRITO", "CABLECAR", "CADDY", "CADDY2", "CAMPER", "CARBONIZZARE", "CHEETAH", "COMET2", "COGCABRIO", "COQUETTE", "CUTTER", "GRESLEY", "DILETTANTE", "DILETTANTE2", "DUNE", "DUNE2", "HOTKNIFE", "DLOADER", "DUBSTA", "DUBSTA2", "DUMP", "RUBBLE", "DOCKTUG", "DOMINATOR", "EMPEROR", "EMPEROR2", "EMPEROR3", "ENTITYXF", "EXEMPLAR", "ELEGY2", "F620", "FBI", "FBI2", "FELON", "FELON2", "FELTZER2", "FIRETRUK", "FLATBED", "FORKLIFT", "FQ2", "FUSILADE", "FUGITIVE", "FUTO", "GRANGER", "GAUNTLET", "HABANERO", "HAULER", "HANDLER", "INFERNUS", "INGOT", "INTRUDER", "ISSI2",
			"JACKAL", "JOURNEY", "JB700", "KHAMELION", "LANDSTALKER", "LGUARD", "MANANA", "MESA", "MESA2", "MESA3", "CRUSADER", "MINIVAN", "MIXER", "MIXER2", "MONROE", "MOWER", "MULE", "MULE2", "ORACLE", "ORACLE2", "PACKER", "PATRIOT", "PBUS", "PENUMBRA", "PEYOTE", "PHANTOM", "PHOENIX", "PICADOR", "POUNDER", "POLICE", "POLICE4", "POLICE2", "POLICE3", "POLICEOLD1", "POLICEOLD2", "PONY", "PONY2", "PRAIRIE", "PRANGER", "PREMIER", "PRIMO", "PROPTRAILER", "RANCHERXL", "RANCHERXL2", "RAPIDGT", "RAPIDGT2", "RADI", "RATLOADER", "REBEL", "REGINA", "REBEL2", "RENTALBUS", "RUINER", "RUMPO", "RUMPO2", "RHINO", "RIOT", "RIPLEY", "ROCOTO", "ROMERO", "SABREGT", "SADLER", "SADLER2", "SANDKING", "SANDKING2", "SCHAFTER2", "SCHWARZER", "SCRAP", "SEMINOLE", "SENTINEL", "SENTINEL2", "ZION", "ZION2", "SERRANO", "SHERIFF", "SHERIFF2", "SPEEDO", "SPEEDO2", "STANIER", "STINGER", "STINGERGT", "STOCKADE", "STOCKADE3", "STRATUM", "SULTAN", "SUPERD", "SURANO", "SURFER", "SURFER2", "SURGE", "TACO", "TAILGATER", "TAXI", "TRASH", "TRACTOR", "TRACTOR2", "TRACTOR3", "GRAINTRAILER", "BALETRAILER", "TIPTRUCK", "TIPTRUCK2", "TORNADO", "TORNADO2", "TORNADO3", "TORNADO4", "TOURBUS",
			"TOWTRUCK", "TOWTRUCK2", "UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3", "VOODOO2", "WASHINGTON", "STRETCH", "YOUGA", "ZTYPE", "SANCHEZ", "SANCHEZ2", "SCORCHER", "TRIBIKE", "TRIBIKE2", "TRIBIKE3", "FIXTER", "CRUISER", "BMX", "POLICEB", "AKUMA", "CARBONRS", "BAGGER", "BATI", "BATI2", "RUFFIAN", "DAEMON", "DOUBLE", "PCJ", "VADER", "VIGERO", "FAGGIO2", "HEXER", "ANNIHILATOR", "BUZZARD", "BUZZARD2", "CARGOBOB", "CARGOBOB2", "CARGOBOB3", "SKYLIFT", "POLMAV", "MAVERICK", "NEMESIS", "FROGGER", "FROGGER2", "CUBAN800", "DUSTER", "STUNT", "MAMMATUS", "JET", "SHAMAL", "LUXOR", "TITAN", "LAZER", "CARGOPLANE", "SQUALO", "MARQUIS", "DINGHY", "DINGHY2", "JETMAX", "PREDATOR", "TROPIC", "SEASHARK", "SEASHARK2", "SUBMERSIBLE", "TRAILERS", "TRAILERS2", "TRAILERS3", "TVTRAILER", "RAKETRAILER", "TANKER", "TRAILERLOGS", "TR2", "TR3", "TR4", "TRFLAT", "TRAILERSMALL", "VELUM", "ADDER", "VOLTIC", "VACCA", "BIFTA", "SPEEDER", "PARADISE", "KALAHARI", "JESTER", "TURISMOR", "VESTRA", "ALPHA", "HUNTLEY", "THRUST", "MASSACRO", "MASSACRO2", "ZENTORNO", "BLADE", "GLENDALE", "PANTO", "PIGALLE", "WARRENER", "RHAPSODY", "DUBSTA3", "MONSTER", "SOVEREIGN", "INNOVATION",
			"HAKUCHOU", "FUROREGT", "MILJET", "COQUETTE2", "BTYPE", "BUFFALO3", "DOMINATOR2", "GAUNTLET2", "MARSHALL", "DUKES", "DUKES2", "STALION", "STALION2", "BLISTA2", "BLISTA3", "DODO", "SUBMERSIBLE2", "HYDRA", "INSURGENT", "INSURGENT2", "TECHNICAL", "SAVAGE", "VALKYRIE", "KURUMA", "KURUMA2", "JESTER2", "CASCO", "VELUM2", "GUARDIAN", "ENDURO", "LECTRO", "SLAMVAN", "SLAMVAN2", "RATLOADER2", "SWIFT2", "LUXOR2", "FELTZER3", "OSIRIS", "VIRGO", "WINDSOR", "BESRA", "SWIFT", "BLIMP2", "VINDICATOR", "TORO", "T20", "COQUETTE3", "CHINO", "BRAWLER" };
		if (id < 0)
		{
			if (id == -1)
			{
				return Convert::ToString(sizeof(A) / sizeof(A[0]));
			}
			else
			{
				PrintDebugMessage(Add3Strings("~r~ERROR: ~s~Array index out of range (", Convert::ToString(id), ") for allvehModels"));
				return "NULL";
			}
		}
		return A[id];
	}
	case Array::ColorNames:
	{
		char* A[161] = { "Black", "Graphite", "Black Steel", "Dark Steel", "Silver", "Bluish Silver", "Rolled Steel", "Shadow Silver", "Stone Silver", "Midnight Silver", "Cast Iron Silver", "Anthracite Black", "Matte Black", "Matte Gray", "Light Gray", "Util Black", "Util Black Poly", "Util Dark Silver", "Util Silver", "Util Gun Metal", "Util Shadow Silver", "Worn Black", "Worn Graphite", "Worn Silver Grey", "Worn Silver", "Worn Blue Silver", "Worn Shadow Silver", "Red", "Torino Red", "Formula Red", "Blaze Red", "Grace Red", "Garnet Red", "Sunset Red", "Cabernet Red", "Candy Red", "Sunrise Orange", "Gold", "Orange", "Red", "Dark Red", "Matte Orange", "Yellow", "Util Red", "Util Bright Red", "Util Garnet Red", "Worn Red", "Worn Golden Red", "Worn Dark Red", "Dark Green", "Metallic Racing Green", "Sea Green", "Olive Green", "Bright Green", "Metallic Gasoline Green", "Matte Lime Green", "Dark Green", "Worn Green", "Worn Sea Wash", "Metallic Midnight Blue", "Metallic Dark Blue", "Galaxy Blue", "Dark Blue", "Saxon Blue", "Blue", "Mariner Blue", "Harbor Blue", "Diamond Blue", "Surf Blue", "Nautical Blue", "Ultra Blue", "Schafter Purpler",
			"Metallic Ultra Blue", "Racing Blue", "Light Blue", "Util Midnight Blue", "Util Blue", "Util Sea Foam Blue", "Util Lightning Blue", "Util Maui Blue Poly", "Util Bright Blue", "Slate Blue", "Dark Blue", "Blue", "Matte Midnight Blue", "Worn Dark Blue", "Worn Blue", "Baby Blue", "Yellow", "Race Yellow", "Bronze", "Dew Yellow", "Metallic Lime", "Metallic Champagne", "Feltzer Brown", "Creek Brown", "Chocolate Brown", "Maple Brown", "Saddle Brown", "Straw Brown", "Moss Brown", "Bison Brown", "Woodbeech Brown", "Beechwood Brown", "Straw Brown", "Sandy Brown", "Bleached Brown", "Cream", "Util Brown", "Util Medium Brown", "Util Light Brown", "Ice White", "Frost White", "Worn Honey Beige", "Worn Brown", "Dark Brown", "Worn Straw Beige", "Brushed Steel", "Brushed Black Steel", "Brushed Alluminum", "Chrome", "Worn Off-White", "Util Off-White", "Worn Orange", "Worn Light Orange", "Pea Green", "Worn Taxi Yellow", "Police Blue", "Green", "Matte Brown", "Worn Orange", "Ice White", "Worn White", "Worn Olive Army Green", "Pure White", "Hot Pink", "Salmon Pink", "Pfister Pink", "Bright Orange", "Green", "Flourescent Blue", "Midnight Blue",
			"Midnight Purple", "Wine Red", "Hunter Green", "Bright Purple", "Midnight Purple", "Carbon Black", "Matte Purple", "Matte Dark Purple", "Metallic Lava Red", "Olive Green", "Matte Olive Drab", "Dark Earth", "Desert Tan", "Matte Foilage Green", "DEFAULT ALLOY", "Epsilon Blue", "Pure Gold", "Brushed Gold", "Secret Gold" };
		if (id < 0)
		{
			if (id == -1)
			{
				return Convert::ToString(sizeof(A) / sizeof(A[0]));
			}
			else
			{
				PrintDebugMessage(Add3Strings("~r~ERROR: ~s~Array index out of range (", Convert::ToString(id), ") for ColorNames"));
				return "NULL";
			}
		}
		return A[id];
	}
	}
}
int getArraySize(int a)
{
	return Convert::ToInt32(getFromArray(a, -1));
}
void LoadVehicle(int slot)
{
	if (VehSaved[slot])
	{
		bool LoadVeh = 0;
		AddOption(SavedVehName[slot], LoadVeh, nullFunc, SUB::SAVEDVEHICLES);
		if (LoadVeh)
		{
			selectedSavedVeh = slot;
		}
	}
}
void AddVehMod(char* modname, int modType, int modIndex)
{
		bool ApplyMod = 0;
		if (modType == 11 || modType == 12 || modType == 13 || modType == 14 || modType == 15 || modType == 16) AddOption(modname, ApplyMod);
        else if (GET_NUM_VEHICLE_MODS(myVeh, modType) > modIndex) AddOption(_GET_LABEL_TEXT(GET_MOD_TEXT_LABEL(myVeh, modType, modIndex)), ApplyMod);
		if (GET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), modType) == modIndex) DrawModSelected();
		if (menu::printingop == menu::currentop)
		{
			if (ApplyMod){ SET_VEHICLE_MOD_KIT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0); SET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), modType, modIndex, 0); }
		}
}
void AddStockVehMod(char* modname, int modType)
{
	bool ApplyMod = 0;
	AddOption(modname, ApplyMod);
	if (GET_VEHICLE_MOD(myVeh, modType) == StockVehModIndex) DrawModSelected();
	if (menu::printingop == menu::currentop)
	{
		if (ApplyMod){ SET_VEHICLE_MOD_KIT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0); REMOVE_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), modType); }
	}
}
void AddToggleVehMod(char* modname, int modType, bool toggle)
{
	//if (menu::totalop == 0) PrintBottomLeft("This Vehicle Does not have any upgrades of this type"); menu::SetSub_previous();
	bool ApplyMod = 0;
	AddOption(modname, ApplyMod);
	if (IS_TOGGLE_MOD_ON(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), modType) == toggle)
	{
		if (OptionY < 0.6325 && OptionY > 0.1425)
		{
			/*SET_TEXT_FONT(0);
			SET_TEXT_SCALE(0.26f, 0.26f);
			SET_TEXT_CENTRE(1);*/

			DRAW_SPRITE("commonmenu", "shop_garage_icon_b", 0.233f + menuPos, 0.015f + OptionY, 0.036f, 0.036f, 0.0f, 255, 255, 255, 255);
		}
	}
	if (menu::printingop == menu::currentop)
	{
		if (ApplyMod){ SET_VEHICLE_MOD_KIT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0); TOGGLE_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), modType, toggle); }
	}
}
void AddCustomVehMod(char* name, bool &toggle, bool &setMod)
{
	AddOption(name, setMod);
	if (toggle) DrawModSelected();
}
void AddWheel(char* wheelname, int modType, int modIndex, int wheeltype)
{
	bool ApplyMod = 0;
	if (DOES_TEXT_LABEL_EXIST(GET_MOD_TEXT_LABEL(TMPVehicle, modType, modIndex))) AddOption(_GET_LABEL_TEXT(GET_MOD_TEXT_LABEL(TMPVehicle, modType, modIndex)), ApplyMod);
	else AddOption(wheelname, ApplyMod);
	if (GET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), modType) == modIndex && GET_VEHICLE_WHEEL_TYPE(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())) == wheeltype && OptionY > 0.01)
	{
		if (OptionY < 0.6325 && OptionY > 0.1425)
		{
			/*SET_TEXT_FONT(0);
			SET_TEXT_SCALE(0.26f, 0.26f);
			SET_TEXT_CENTRE(1);*/

			DRAW_SPRITE("commonmenu", "shop_garage_icon_b", 0.233f + menuPos, 0.015f + OptionY, 0.036f, 0.036f, 0.0f, 255, 255, 255, 255);
		}
	}
	if (menu::printingop == menu::currentop)
	{
		if (ApplyMod){ SET_VEHICLE_MOD_KIT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0); SET_VEHICLE_WHEEL_TYPE(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), wheeltype); SET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), modType, modIndex, 0); }
	}
}
void UpdateNotification(int nIndex)
{
	Notification notification = notifications[nIndex];
	switch (notification.NotificationState)
	{
	case 1:
	{
		if (notification.NotificationY > 0.11 + (nIndex * 0.09)) notification.NotificationY -= 0.004;
		if (notification.NotificationSpriteAlpha < 255) { notification.NotificationSpriteAlpha += 5; if (notification.NotificationSpriteAlpha > 255) { notification.NotificationSpriteAlpha = 255; } }
		if (notification.NotificationTextX < 0.08) notification.NotificationTextX += notification.speed;
		if (menuPos < 0.22605) menuPos += 0.02;
		notification.NotificationSpriteX += notification.speed;
		notification.speed += 0.0002;
		DRAW_SPRITE("commonmenu", "gradient_bgd", notification.NotificationSpriteX, notification.NotificationY, 0.40, 0.08, 0.0, 255, 255, 255, notification.NotificationSpriteAlpha);
		SET_TEXT_COLOUR(255, 255, 255, notification.NotificationSpriteAlpha);
		SET_TEXT_FONT(4);
		SET_TEXT_SCALE(0.534f, 0.534f);
		SET_TEXT_CENTRE(0);
		_SET_TEXT_ENTRY("STRING");
		_ADD_TEXT_COMPONENT_STRING(notification.NotificationText);
		_DRAW_TEXT(notification.NotificationTextX, notification.NotificationY - 0.01);
		if (notification.NotificationSpriteX > 0.08) { notification.NotificationState = 2; notification.NotificationTimer = GET_GAME_TIMER() + 4000; notification.speed = 0.002; }
		notifications[nIndex] = notification;
		return;
	}
	case 2:
	{
		if (notification.NotificationY > 0.11 + (nIndex * 0.09)) notification.NotificationY -= 0.004;
		DRAW_SPRITE("commonmenu", "gradient_bgd", notification.NotificationSpriteX, notification.NotificationY, 0.40, 0.08, 0.0, 255, 255, 255, notification.NotificationSpriteAlpha);
		SET_TEXT_COLOUR(255, 255, 255, 255);
		SET_TEXT_FONT(4);
		SET_TEXT_SCALE(0.534f, 0.534f);
		SET_TEXT_CENTRE(0);
		_SET_TEXT_ENTRY("STRING");
		_ADD_TEXT_COMPONENT_STRING(notification.NotificationText);
		_DRAW_TEXT(0.082, notification.NotificationY - 0.01);
		if (GET_GAME_TIMER() >= notification.NotificationTimer) { notification.NotificationState = 3; }
		notifications[nIndex] = notification;
		return;
	}
	case 3:
	{
		if (notification.NotificationY > 0.11 + (nIndex * 0.09)) notification.NotificationY -= 0.004;
		if (notification.NotificationSpriteAlpha > 0) { notification.NotificationSpriteAlpha -= 5; if (notification.NotificationSpriteAlpha < 0) { notification.NotificationSpriteAlpha = 0; } }
		if (notification.NotificationTextX > -0.20) notification.NotificationTextX -= notification.speed;
		notification.NotificationSpriteX -= notification.speed;
		notification.speed += 0.0002;
		DRAW_SPRITE("commonmenu", "gradient_bgd", notification.NotificationSpriteX, notification.NotificationY, 0.40, 0.08, 0.0, 255, 255, 255, notification.NotificationSpriteAlpha);
		SET_TEXT_COLOUR(255, 255, 255, notification.NotificationSpriteAlpha);
		SET_TEXT_FONT(4);
		SET_TEXT_SCALE(0.534f, 0.534f);
		SET_TEXT_CENTRE(0);
		_SET_TEXT_ENTRY("STRING");
		_ADD_TEXT_COMPONENT_STRING(notification.NotificationText);
		_DRAW_TEXT(notification.NotificationTextX, notification.NotificationY - 0.01);
		notifications[nIndex] = notification;
		if (notification.NotificationSpriteX < -0.20) 
		{
			if (NotificationCount == 1) { notifications[nIndex].NotificationState = 4; }
			else
			{
				for (int i = 1; i < NotificationCount; i++)
				{
					notifications[i - 1] = notifications[i];
				}
				NotificationCount--;
			}
		}
		return;
	}
	case 4:
	{
		menuPos -= 0.02;
		if (menuPos <= 0) { LoopNotification = 0; NotificationCount = 0;  }
		return;
	}
	}
}
void NotificationLoop()
{
	for (int i = 0; i < NotificationCount; i++)
	{
		UpdateNotification(i);
	}
}
Notification newNotification(char* text)
{
	return {text, 1, 0, 0, -0.20, -0.20, 0.11f + (NotificationCount * 0.09f), 0.002 };
}
void PrintNotification(char* text)
{
	notifications[NotificationCount] = newNotification(text);
	NotificationCount++;
	LoopNotification = 1;
}


// Hax functions:
void set_massacre_mode()
{
	float tempCoords1[3];
	DWORD tempHash;
	DWORD tempPed = PLAYER_PED_ID();
	DWORD tempVehicle;
	bool tick = 0;

	offset_from_entity(tempPed, GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f), tempCoords1);

	// Kick away naughty players
	for (int i = 0; i <= 29; i++)
	{
		if (IS_PLAYER_TARGETTING_ENTITY(i, tempPed) || IS_PLAYER_FREE_AIMING_AT_ENTITY(i, tempPed))
		{
			if (!tick)
			{
				PrintStringBottomCentre("~h~You~s~ are being aimed at. Taking care of it!");
				tick = true;
			}
			APPLY_FORCE_TO_ENTITY(GET_PLAYER_PED(i), 1, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 1, 1, 1, 1, 0, 1);
		}
	}

	// Kick away nearest vehicle
	tempVehicle = GET_CLOSEST_VEHICLE(tempCoords1[0], tempCoords1[1], tempCoords1[2], 400.0f, 0, 4);
	if (DOES_ENTITY_EXIST(tempVehicle)) APPLY_FORCE_TO_ENTITY(tempVehicle, 1, 5.0f, 5.0f, 5.0f, 5.0f, 13.0f, 6.5f, 1, 1, 1, 1, 0, 1);

	// Exploding vehicles
	switch (GET_RANDOM_INT_IN_RANGE(1, 10))
	{
	case 1: tempHash = 3945366167; break;
	case 2: tempHash = 92612664; break;
	case 3: tempHash = 1488164764; break;
	case 4: tempHash = 117401876; break;
	case 5: tempHash = 408192225; break;
	case 6: tempHash = 3863274624; break;
	case 7: tempHash = 165154707; break;
	case 8: tempHash = 1011753235; break;
	case 9: tempHash = 941800958; break;
	case 10: tempHash = 970385471; break;
	}

	tempVehicle = CREATE_VEHICLE(tempHash, tempCoords1[0], tempCoords1[1], tempCoords1[2], GET_RANDOM_FLOAT_IN_RANGE(0.0f, 360.0f), 1, 1);
	APPLY_FORCE_TO_ENTITY(tempVehicle, 1, 5.0f, 5.0f, 5.0f, 5.0f, 13.0f, 6.5f, 1, 1, 1, 1, 0, 1);
	NETWORK_EXPLODE_VEHICLE(tempVehicle, 1, 1, 1);

	// Dying peds
	switch (GET_RANDOM_INT_IN_RANGE(1, 10))
	{
	case 1: tempHash = 1682622302; break;
	case 2: tempHash = 113504370; break;
	case 3: tempHash = 4244282910; break;
	case 4: tempHash = 808859815; break;
	case 5: tempHash = 1004114196; break;
	case 6: tempHash = 3696858125; break;
	case 7: tempHash = 921110016; break;
	case 8: tempHash = 880829941; break;
	case 9: tempHash = 1462895032; break;
	case 10: tempHash = 773063444; break;
	}

	offset_from_entity(tempPed, GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f), tempCoords1);
	tempPed = CREATE_PED(22, tempHash, tempCoords1[0], tempCoords1[1], tempCoords1[2], GET_RANDOM_FLOAT_IN_RANGE(0.0f, 360.0f), 1, 1);
	APPLY_FORCE_TO_ENTITY(tempPed, 1, 5.0f, 5.0f, 5.0f, 5.0f, 13.0f, 6.5f, 1, 1, 1, 1, 0, 1);
	EXPLODE_PED_HEAD(tempPed, 324506233);
	ADD_EXPLOSION(tempCoords1[0], tempCoords1[1], tempCoords1[2], 26, 4.0f, 1, 0, 3.0f);

	// Water hydrants
	offset_from_entity(tempPed, GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f), tempCoords1);
	ADD_EXPLOSION(tempCoords1[0], tempCoords1[1], tempCoords1[2], 13, 8.0f, 1, 0, 3.0f);

	// Zombies
	offset_from_entity(tempPed, GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f), tempCoords1);
	tempPed = CREATE_PED(22, -1404353274, tempCoords1[0], tempCoords1[1], tempCoords1[2], GET_RANDOM_FLOAT_IN_RANGE(0.0f, 360.0f), 1, 1);
	PED_TO_NET(tempPed);
	SET_PED_COMBAT_ABILITY(tempPed, 100);
	TASK_COMBAT_HATED_TARGETS_AROUND_PED(tempPed, 400.0f, 0);
}
void sample_createEscort()
{
	if (!IS_WAYPOINT_ACTIVE()) PrintStringBottomCentre("~r~Error:~s~ No waypoint set.");
	else
	{
		float Pos[3];
		Vector3 Coord = GET_BLIP_COORDS(GET_FIRST_BLIP_INFO_ID(_GET_BLIP_INFO_ID_ITERATOR()));
		GET_GROUND_Z_FOR_3D_COORD(Coord.x, Coord.y, Coord.z, &Coord.z);
		VectorToFloat(GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER_PED_ID(), 0.0f, 5.0f, 1.0f), Pos);
		WAIT(10);
		DWORD tempPed = CREATE_PED(1, GET_HASH_KEY("A_C_CHIMP"), Pos[0], Pos[1], Pos[2], 0.0f, 1, 1);
		DWORD tempVehicle = CREATE_VEHICLE(GET_HASH_KEY("KURUMA2"), Pos[0], Pos[1], Pos[2] + 2.0f, GET_ENTITY_HEADING(PLAYER_PED_ID()), 1, 1);
		RequestControlOfEnt(tempVehicle);
		SET_VEHICLE_COLOURS(tempVehicle, 0, 0);
		SET_VEHICLE_NUMBER_PLATE_TEXT(tempVehicle, "VIP");
		for (int i = -1; i <= 20; i++)
		{
			if (!IS_VEHICLE_SEAT_FREE(tempVehicle, i)) continue;
			TASK_WARP_PED_INTO_VEHICLE(PLAYER_PED_ID(), tempVehicle, i); break;
		}
		TASK_VEHICLE_MISSION_COORS_TARGET(tempPed, tempVehicle, Coord.x, Coord.y, Coord.z, 4, 20.0f, 786469, 20.0f, 10.0f, 1);
	}
}
DWORD grav_partfx, grav_entity; bool grav_toggled = 0, grav_target_locked = 0;
Vector3 get_coords_from_cam(float distance)
{
	Vector3 Rot = GET_GAMEPLAY_CAM_ROT(2);
	static Vector3 Coord = GET_GAMEPLAY_CAM_COORD();

	Rot.y = distance * cos(Rot.x);
	Coord.x = Coord.x + Rot.y * sin(Rot.z * -1.0f);
	Coord.y = Coord.y + Rot.y * cos(Rot.z * -1.0f);
	Coord.z = Coord.z + distance * sin(Rot.x);

	return Coord;
}
void set_gravity_gun()
{
	DWORD tempPed, tempWeap;

	if (!grav_target_locked) GET_PLAYER_TARGET_ENTITY(PLAYER_ID(), &grav_entity);

	tempPed = PLAYER_ID(); GET_CURRENT_PED_WEAPON(PLAYER_PED_ID(), &tempWeap, 1);
	if ((IS_PLAYER_FREE_AIMING(tempPed) || IS_PLAYER_TARGETTING_ANYTHING(tempPed)) && DOES_ENTITY_EXIST(grav_entity) && tempWeap == 453432689)
	{
		if (!grav_target_locked) GET_PLAYER_TARGET_ENTITY(PLAYER_ID(), &grav_entity); grav_target_locked = true;
		float Coord[3]; VectorToFloat(get_coords_from_cam(5.5f), Coord);

		if (!DOES_PARTICLE_FX_LOOPED_EXIST(grav_partfx))
		{
			REQUEST_PTFX_ASSET();
			if (HAS_PTFX_ASSET_LOADED())
			{
				grav_partfx = START_PARTICLE_FX_LOOPED_AT_COORD((DWORD*)"scr_drug_traffic_flare_L", Coord[0], Coord[1], Coord[2], 0.0f, 0.0f, 0.0f, 0.5f, 0, 0, 0, 0);
				SET_PARTICLE_FX_LOOPED_COLOUR(grav_partfx, 1.0f, 0.84f, 0.0f, 0);
			}
		}

		RequestControlOfid(NETWORK_GET_NETWORK_ID_FROM_ENTITY(grav_entity));
		RequestControlOfEnt(grav_entity);
		SET_ENTITY_COORDS_NO_OFFSET(grav_entity, Coord[0], Coord[1], Coord[2], 0, 0, 0);
		if (IS_ENTITY_A_VEHICLE(grav_entity)) SET_ENTITY_HEADING(grav_entity, GET_ENTITY_HEADING(PLAYER_PED_ID()) + 90.0f);

		if (IS_PED_SHOOTING(PLAYER_PED_ID()))
		{
			PLAY_SOUND_FROM_ENTITY(-1, (DWORD*)"Foot_Swish", grav_entity, (DWORD*)"docks_heist_finale_2a_sounds", 0, 0);
			SET_ENTITY_HEADING(grav_entity, GET_ENTITY_HEADING(PLAYER_PED_ID()));
			APPLY_FORCE_TO_ENTITY(grav_entity, 1, 0.0f, 350.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
			grav_target_locked = false;
		}
	}
	else if (DOES_PARTICLE_FX_LOOPED_EXIST(grav_partfx))
	{
		STOP_PARTICLE_FX_LOOPED(grav_partfx, 0);
		REMOVE_PARTICLE_FX(grav_partfx, 0);
		REMOVE_PTFX_ASSET();
	}
	if (!IS_PLAYER_FREE_AIMING_AT_ENTITY(tempPed, grav_entity) || !IS_PLAYER_TARGETTING_ENTITY(tempPed, grav_entity)) grav_target_locked = false;

}
static bool nosBinds()
{
	return (IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_LS)) || (IsKeyDown(VK_SHIFT));
}
static bool superrunBinds()
{
	return (IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_ACCEPT)) || (IsKeyDown(VK_SHIFT));
}
static bool vehRocketsBinds()
{
	return (!VehWeaponAtKeyDown &&  IS_DISABLED_CONTROL_JUST_RELEASED(2, INPUT_FRONTEND_LS)) || (VehWeaponAtKeyDown &&  IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_LS)) || (VehWeaponAtKeyDown && IsKeyDown(0x6B) || (!VehWeaponAtKeyDown && IsKeyJustUp(0x6B)));
}

//bool activenos = false;
//void ToggleNos()
//{
//	if (!activenos) {
//		PrintBottomLeft(AddStrings("Vehicle Nos: ", "ON"));
//		activenos = true;
//	}
//
//	else if (activenos){
//		PrintBottomLeft(AddStrings("Vehicle Nos: ", "OFF"));
//		activenos = false;
//	}
//}
void nosloop()
{
	if (nosBinds())
	{
		SET_VEHICLE_BOOST_ACTIVE(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 1);
		_START_SCREEN_EFFECT("RaceTurbo", 0, 0);
		if (IS_VEHICLE_ON_ALL_WHEELS(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())))
		{
			APPLY_FORCE_TO_ENTITY(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), true, 0, 3.0f, 0, 0, 0, 0, true, true, true, true, false, true);
		}
		SET_VEHICLE_BOOST_ACTIVE(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0);
	}
}

//bool superruncheck = false;
//void superrun()
//{
//	if (!superruncheck) {
//		PrintBottomLeft(AddStrings("Super Run: ", "ON"));
//		superruncheck = true;
//	}
//
//	else if (superruncheck){
//		PrintBottomLeft(AddStrings("Super Run: ", "OFF"));
//		superruncheck = false;
//	}
//}

void superrun_loop()
{
	if (superrunBinds())
	{
		APPLY_FORCE_TO_ENTITY(PLAYER_PED_ID(), true, 0, 3.0f, 0, 0, 0, 0, true, true, true, true, false, true);
	}
}
	

bool super_check = false;
//void Superman__mode()
//{
	//if (!super_check) {
		//GIVE_DELAYED_WEAPON_TO_PED(PLAYER_PED_ID(), 0xFBAB5776, 1, 1);
		//APPLY_FORCE_TO_ENTITY(PLAYER_PED_ID(), true, 0, 0, 40, 0, 0, 0, true, true, true, true, false, true);
		//SET_PLAYER_INVINCIBLE(PLAYER_ID(), true);
		//PrintBottomLeft(AddStrings("Superman: ", "ON"));
		//super_check = true;
	//}
	//else if (super_check) {
		//PrintBottomLeft(AddStrings("Superman: ", "OFF"));
		//super_check = false;
	//}
//}

void super_loop()
{
		APPLY_FORCE_TO_ENTITY(PLAYER_PED_ID(), true, 0, 100, 100, 0, 0, 0, false, true, false, false, false, true);
}
static bool boostBinds()
{
	return (IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_RB)) || (IsKeyDown(VK_NUMPAD9));
}
//bool boost_check = false;
//void Boost__r1()
//{
//	if (!boost_check){
//		PrintBottomLeft(AddStrings("Boost with R1: ", "ON"));
//		boost_check = true;
//	}
//
//	else if (boost_check){
//		PrintBottomLeft(AddStrings("Boost with R1: ", "OFF"));
//		boost_check = false;
//	}
//}
void boostloop()
{
	if (boostBinds())
	{
		SET_VEHICLE_FORWARD_SPEED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 100.0f);
	}
}


static bool sbrakeBinds()
{
	return (IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_LB)) || (IsKeyDown(VK_SPACE));
}

//bool sbrake_check = false;
//void sbrake_l1()
//{
//	if (!sbrake_check){
//		PrintBottomLeft(AddStrings("Super Brake with L1: ", "ON"));
//		sbrake_check = true;
//	}
//
//	else if (sbrake_check){
//		PrintBottomLeft(AddStrings("Super Brake with L1: ", "OFF"));
//		sbrake_check = false;
//	}
//}
void sbrakeloop()
{
	if (sbrakeBinds())
	{
		SET_VEHICLE_FORWARD_SPEED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0.0f);
	}
}

static bool carjumpereBinds()
{
	return (IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_X)) || (IsKeyDown(VK_NUMPAD0));
}

//bool carjump_check = false;
//void car_jumper()
//{
//	if (!carjump_check){
//		PrintBottomLeft(AddStrings("Car Jumper: ", "ON"));
//		carjump_check = true;
//	}
//
//	else if (carjump_check){
//		PrintBottomLeft(AddStrings("Car Jumper: ", "OFF"));
//		carjump_check = false;
//	}
//}
void CarJumpLoop()
{
	if (carjumpereBinds())
	{
		int Handle = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());
		if (Handle != 0)
		{
				APPLY_FORCE_TO_ENTITY(Handle, true, 0, 0, 2, 0, 0, 0, true, true, true, true, false, true);
			}
	}
}

//void unl_ammo()
//{
//	if (!ammo_check){
//		SET_PED_INFINITE_AMMO_CLIP(PLAYER_PED_ID(), true);
//		UNLAMMOONOFF = "Unlimited ammo  ~g~ON";
//		PrintStringBottomCentre(AddStrings("Unlimited ammo  ", "~g~ON"));
//		ammo_check = true;
//	}
//
//
//	else if (ammo_check){
//		SET_PED_INFINITE_AMMO_CLIP(PLAYER_PED_ID(), false);
//		UNLAMMOONOFF = "Unlimited ammo  ~r~OFF";
//		PrintStringBottomCentre(AddStrings("Unlimited ammo  ", "~r~OFF"));
//		ammo_check = false;
//	}
//}


//bool godmode_check = false;
//void Player_Godmode()
//{
//	if (!godmode_check){
//		SET_ENTITY_INVINCIBLE(PLAYER_PED_ID(), true);
//		GODMODEONOFF = "Godmode  ~g~ON";
//		PrintStringBottomCentre(AddStrings("Godmode  ", "~g~ON"));
//		godmode_check = true;
//	}
//
//	else if (godmode_check){
//		SET_ENTITY_INVINCIBLE(PLAYER_PED_ID(), false);
//		GODMODEONOFF = "Godmode  ~r~OFF";
//		PrintStringBottomCentre(AddStrings("Godmode  ", "~r~OFF"));
//		godmode_check = false;
//	}
//}
bool VehGodmodeCheck = false;
//void VehicleGodmode()
//{
//	if (!VehGodmodeCheck){
//		SET_ENTITY_INVINCIBLE(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), true);
//		VEHICLEGODMDOEONOFF = "Vehicle Godmode  ~g~ON";
//		PrintStringBottomCentre(AddStrings("Vehicle Godmode  ", "~g~ON"));
//		VehGodmodeCheck = true;
//	}
//
//	else if (VehGodmodeCheck){
//		SET_ENTITY_INVINCIBLE(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), false);
//		VEHICLEGODMDOEONOFF = "Vehicle Godmode  ~r~OFF";
//		PrintStringBottomCentre(AddStrings("Vehicle Godmode  ", "~r~OFF"));
//		VehGodmodeCheck = false;
//	}
//}
void GodmodeLoop() { SET_PLAYER_INVINCIBLE(PLAYER_ID(), true); }

void VehGodmodeLoop() { SET_ENTITY_INVINCIBLE(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), true); }


//bool veh_rockets_check = false;
//void vehrockets()
//{
	//if (!veh_rockets_check){
		//PrintBottomLeft(AddStrings("Vehicle Rockets: ", "ON"));
		//veh_rockets_check = true;
	//}

	//else if (veh_rockets_check){
		//PrintBottomLeft(AddStrings("Vehicle Rockets: ", "OFF"));
		//veh_rockets_check = false;
	//}
//
//}
void VehWeaponsLoop()
{
	if (vehRocketsBinds())
	{
		IS_PLAYER_CONTROL_ON(PLAYER_ID()) && IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), 0);
	{
		Vehicle veh = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());

		Vector3 v0, v1;
		GET_MODEL_DIMENSIONS(GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAsset = GET_HASH_KEY(SelectedVehWeaponModel);
		if (!HAS_WEAPON_ASSET_LOADED(weaponAsset))
		{
			REQUEST_WEAPON_ASSET(weaponAsset, 31, 0);
			while (!HAS_WEAPON_ASSET_LOADED(weaponAsset))
				WAIT(0);
		}

		Vector3 coords0from = GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAsset, PLAYER_PED_ID(), 1, 0, -1.0);
		SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAsset, PLAYER_PED_ID(), 1, 0, -1.0);
	}
	}
}
bool ped_target_check = false;
void set__ped_can_be_Targetted_test()
{
	if (!ped_target_check){
		SET_PED_CAN_BE_TARGETTED(PLAYER_PED_ID(), false);
		PrintBottomLeft(AddStrings("SET_PED_CAN_BE_TARGETTED: ", "ON"));
		ped_target_check = true;
	}

	else if (ped_target_check){
		SET_PED_CAN_BE_TARGETTED(PLAYER_PED_ID(), true);
		PrintBottomLeft(AddStrings("SET_PED_CAN_BE_TARGETTED: ", "OFF"));
		ped_target_check = false;
	}

}

static bool WaypointCheck()
{
	return (IS_PED_SITTING_IN_ANY_VEHICLE(PLAYER_PED_ID())) && (IS_WAYPOINT_PLAYBACK_GOING_ON_FOR_PED(PLAYER_PED_ID()));
}
bool radarphone_check = false;
void RadarPhoneTest()

{
	if (!radarphone_check){
		PrintBottomLeft(AddStrings("Radar Phone Test: ", "ON"));
		radarphone_check = true;
	}

	else if (radarphone_check){
		PrintBottomLeft(AddStrings("Radar Phone Test: ", "OFF"));
		radarphone_check = false;
	}


}

void RadarPhoneLoop()

{
	if (IS_PED_RUNNING_MOBILE_PHONE_TASK(PLAYER_PED_ID()))
	{
		DISPLAY_RADAR(true);
	}

	else if (IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), true) && IS_WAYPOINT_ACTIVE())
	{ 
		DISPLAY_RADAR(true);
	}

	else
	{
		DISPLAY_RADAR(false);
	}

}

void FixCarLoop()
{
	if (_IS_VEHICLE_DAMAGED(myVeh))
	{
		SET_VEHICLE_FIXED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()));
	}
	if (GET_VEHICLE_ENGINE_HEALTH(myVeh) < 400)
	{
		SET_VEHICLE_ENGINE_HEALTH(myVeh, 1000);
	}
}
void NeverWantedLoop()
{
	CLEAR_PLAYER_WANTED_LEVEL(PLAYER_ID());
}
void UnlimitedAbilityLoop()
{
	_RECHARGE_SPECIAL_ABILITY(PLAYER_ID(), 1);
}
void SuperJumpLoop()
{
	SET_SUPER_JUMP_THIS_FRAME(PLAYER_ID());
}
static bool VehJetpackUpBinds()
{
	return (IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_RB)) || (IsKeyDown(VK_NUMPAD9));
}
static bool VehJetpackDownBinds()
{
	return (IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_ACCEPT)) || (IsKeyDown(VK_NUMPAD3));
}
static bool VehJetpackForwardBinds()
{
	return (IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_RT)) || (IsKeyDown(VK_NUMPAD8));
}
void Test1()
{
	SET_RADAR_AS_INTERIOR_THIS_FRAME(GET_HASH_KEY("v_fakeboatpo1sh1sunk"), 165.34, -2350.03, 0, 1);
}
void DriveUnderWaterLoop()
{
	if (IS_ENTITY_IN_WATER(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())))
	{
		SET_VEHICLE_ENGINE_HEALTH(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 1000);
		SET_VEHICLE_ENGINE_ON(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), true, true);
	}
}
void FireworkGun()
{
	Vector3 excoords[3];
	float excoords2[3];
	int ped_id = PLAYER_PED_ID();
	if (IS_PED_SHOOTING(ped_id))
	{
		if (GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER_PED_ID(), excoords))
		{
			ADD_EXPLOSION(excoords2[0], excoords2[1], excoords2[2], 36, 5.0, 1, 0, 0);
		}
	}
}
void CashDropLoop()
{
	RequestModel(0x113FD533);
	Vector3 pp = GET_ENTITY_COORDS(PLAYER_PED_ID(), 1);
	for (int i = 0; i < 6; i++){
		CREATE_AMBIENT_PICKUP(GET_HASH_KEY("PICKUP_MONEY_CASE"), pp.x, pp.y + 0.1, pp.z + 0.8, 0, 40000, 0x113FD533, FALSE, TRUE);
		CREATE_AMBIENT_PICKUP(GET_HASH_KEY("PICKUP_MONEY_CASE"), pp.x, pp.y - 0.1, pp.z + 0.8, 0, 40000, 0x113FD533, FALSE, TRUE);
		CREATE_AMBIENT_PICKUP(GET_HASH_KEY("PICKUP_MONEY_CASE"), pp.x + 0.1, pp.y, pp.z + 0.8, 0, 40000, 0x113FD533, FALSE, TRUE);
		CREATE_AMBIENT_PICKUP(GET_HASH_KEY("PICKUP_MONEY_CASE"), pp.x - 0.1, pp.y, pp.z + 0.8, 0, 40000, 0x113FD533, FALSE, TRUE);
	}
	//SET_MODEL_AS_NO_LONGER_NEEDED(0x113FD533);
}
void TeleportToMarker()
{
	bool groundFound = false;
	Entity e = PLAYER_PED_ID();
	if (IS_PED_IN_ANY_VEHICLE(e, 0))
		e = GET_VEHICLE_PED_IS_USING(e);


	Vector3 coords1;
	bool success = false;
	{
		bool blipFound = false;
		// search for marker blip
		int blipIterator = _GET_BLIP_INFO_ID_ITERATOR();
		for (Blip i = GET_FIRST_BLIP_INFO_ID(blipIterator); DOES_BLIP_EXIST(i) != 0; i = GET_NEXT_BLIP_INFO_ID(blipIterator))
		{
			if (GET_BLIP_INFO_ID_TYPE(i) == 4)
			{
				coords1 = GET_BLIP_INFO_ID_COORD(i);
				blipFound = true;
				//PrintBottomLeft("Blip found");
				break;
			}
		}
		if (blipFound)
		{
			// load needed map region and check height levels for ground existence
			groundFound = false;
			static float groundCheckHeight[] = {
				100.0, 110.0, 120.0, 130.0, 140.0, 150.0,90.0, 80.0, 70.0, 60.0, 50.0, 40.0,  30.0, 20.0, 10.0, 5.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0,
				450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0
			};
			/*for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
			{*/
				SET_ENTITY_COORDS_NO_OFFSET(e, coords1.x, coords1.y, -210.00, 0, 0, 1);
				WAIT(100);
				/*if (GET_GROUND_Z_FOR_3D_COORD(coords1.x, coords1.y, groundCheckHeight[i], &coords1.z))
				{
					groundFound = true;
					coords1.z += 3.0;
					//PrintBottomLeft("Ground found");
					break;
				}
			}*/
		}


		if (!groundFound)
		{
			{
			//	PrintBottomLeft("Ground not found");
				coords1.z = 1000.0;
				GIVE_DELAYED_WEAPON_TO_PED(PLAYER_PED_ID(), 0xFBAB5776, 1, 0);
			}
			success = true;
		}
		if (!blipFound)
		{
			PrintBottomLeft("~r~ERROR ~s~ Waypoint not set");
		}

	}
	
}
void BrawlerLoop()
{ 
	if (IS_PED_IN_MODEL(PLAYER_PED_ID(), GET_HASH_KEY("BRAWLER")))
	{
		if (IS_VEHICLE_ON_ALL_WHEELS(myVeh))
		{
			APPLY_FORCE_TO_ENTITY(myVeh, true, 0, 0, -0.25, 0, 0, 0, true, true, true, true, false, true);
		}
	}
}
static bool TrainForward()
{
	return (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_RT) || (IsKeyDown(VK_NUMPAD8)));
}
static bool TrainBackward()
{
	return (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_LT) || (IsKeyDown(VK_NUMPAD2)));
}
void TrainSpeedControl()
{
	SET_ENTITY_MAX_SPEED(Train1, 99999999999);
	if (TrainForward())
	{
		TrainSpeed = GET_ENTITY_SPEED(Train1) + 1;
	}

	else if (TrainBackward())
	{
		TrainSpeed = GET_ENTITY_SPEED(Train1) - 1;
	}
	SET_TRAIN_SPEED(Train1, TrainSpeed);

}
void SpawnPedinSlot(char* PedModel, char* PedName)
{

	Vector3 pos = GET_ENTITY_COORDS(PLAYER_PED_ID(), 0);

	int PedType = GET_PED_TYPE(GET_HASH_KEY(PedModel));
	if (IS_MODEL_VALID(GET_HASH_KEY(PedModel)))
	{
		REQUEST_MODEL(GET_HASH_KEY(PedModel));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY(PedModel))) WAIT(5);
                for (int i = 0; i < PedSpawnerSlots; i++)
					if (!PedSlotUsed[i]){ 
						PedSlots[i] = CREATE_PED(PedType, GET_HASH_KEY(PedModel), pos.x, pos.y, pos.z, GET_ENTITY_HEADING(PLAYER_PED_ID()), true, true);
						PedNameSlot[i] = PedName;
						if (PedSpawnInvincible){ SET_ENTITY_INVINCIBLE(PedSlots[i], true); }
						if (PedSpawnAsBodyguard){ SET_PED_AS_GROUP_MEMBER(PedSlots[i], GET_PLAYER_GROUP(PLAYER_PED_ID())); }
						if (PedSpawnWithBlip){ BlipPedSlots[i] = ADD_BLIP_FOR_ENTITY(PedSlots[i]); SET_BLIP_COLOUR(BlipPedSlots[i], 2); }
						PrintBottomLeft(AddStrings(PedName, " Spawned"));
						PedSlotUsed[i] = 1;
						for (int w = 0; w < 55; w++)
							if (PedSpawnWithWeapon[w]) GIVE_DELAYED_WEAPON_TO_PED(PedSlots[i], GET_HASH_KEY(getFromArray(Array::WeaponModels, w)), 9999, 1);
						i = PedSpawnerSlots + 1;
					}

	}
	else
	{
		PrintBottomLeft("~r~ERROR:~s~ Invalid Model");
	}
}
void TorqueMultiplier()
{
	_SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), TorqueMultiValue);

	if (!IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), true))
	{
		TorqueMultiCheck = false;
	}
}
void DriveOnWater()
{
	Vector3 PlayerCoords = GET_ENTITY_COORDS(PLAYER_PED_ID(), true);
	GET_WATER_HEIGHT(PlayerCoords.x, PlayerCoords.y, PlayerCoords.z, &WaterHeight);
	SET_ENTITY_COORDS(DriveOnWaterObject, PlayerCoords.x, PlayerCoords.y, WaterHeight - 2.00, true, true, true, 1);
	SET_ENTITY_ROTATION(DriveOnWaterObject, 180, 90, 180, 1, 2);
}
void CustomBullets_()
{
	Vector3 Pos;
	(GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER_PED_ID(), &Pos));

	if (IS_PED_SHOOTING(PLAYER_PED_ID()))
	{
		if (CBMoneyBag)
		{
			REQUEST_MODEL(0x113FD533);
			if (HAS_MODEL_LOADED(0x113FD533))
			{
				CREATE_AMBIENT_PICKUP(GET_HASH_KEY("PICKUP_MONEY_CASE"), Pos.x, Pos.y, Pos.z, 0, 40000, 0x113FD533, FALSE, TRUE);
			}
		}

		if (CBTeleGun){
			SET_ENTITY_COORDS(PLAYER_PED_ID(), Pos.x, Pos.y, Pos.z, 0, 0, 0, 1);
		}

		if (CBVehGun){
			Hash RandomVeh = GET_HASH_KEY(getFromArray(Array::allvehModels, GET_RANDOM_INT_IN_RANGE(0, 361)));
			Vehicle veh = 2500000000;
			Vector3 coords = GET_ENTITY_COORDS(PLAYER_PED_ID(), 1);
			float Heading = GET_ENTITY_HEADING(PLAYER_PED_ID());
			REQUEST_MODEL(RandomVeh);
			while (!HAS_MODEL_LOADED(RandomVeh)) WAIT(0);
			{
				if (Heading <= 135 && Heading >= 46)
				{
					veh = CREATE_VEHICLE(RandomVeh, coords.x + 5.0, coords.y, coords.z, GET_ENTITY_HEADING(PLAYER_PED_ID()), true, 0);
				}
				else if (Heading <= 225 && Heading >= 136)
				{
					veh = CREATE_VEHICLE(RandomVeh, coords.x, coords.y + 5.0, coords.z, GET_ENTITY_HEADING(PLAYER_PED_ID()), true, 0);
				}
				else if (Heading <= 315 && Heading >= 226)
				{
					veh = CREATE_VEHICLE(RandomVeh, coords.x - 5.0, coords.y, coords.z, GET_ENTITY_HEADING(PLAYER_PED_ID()), true, 0);
				}
				else if (Heading <= 45 && Heading >= 316)
				{
					veh = CREATE_VEHICLE(RandomVeh, coords.x, coords.y - 5.0, coords.z, GET_ENTITY_HEADING(PLAYER_PED_ID()), true, 0);
				}
				SET_VEHICLE_FORWARD_SPEED(veh, 50.0f);
				if (!DOES_ENTITY_EXIST(veh)){
					PrintDebugMessage("~r~ERROR:~s~ Faild to spawn vehicle");
					for (int i = 0; i < getArraySize(Array::allvehModels); i++)
						SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY(getFromArray(Array::allvehModels, i)));
					PrintDebugMessage("All Models Set as no longer needed");
					CLEAR_AREA_OF_VEHICLES(coords.x, coords.y, coords.z, 100.0, 1, 1, 1, 1, 1);
					PrintDebugMessage("All vehicles in area deleted");
				}
			}
		}

		if (CBRpg){
				REQUEST_WEAPON_ASSET(GET_HASH_KEY("WEAPON_VEHICLE_ROCKET"), 31, 0);
				while (!HAS_WEAPON_ASSET_LOADED(GET_HASH_KEY("WEAPON_VEHICLE_ROCKET"))) WAIT(0);
				SHOOT_SINGLE_BULLET_BETWEEN_COORDS(Pos.x, Pos.y, Pos.z, Pos.x, Pos.y, Pos.z, 250, 1, GET_HASH_KEY("WEAPON_VEHICLE_ROCKET"), PLAYER_PED_ID(), 1, 0, -1.0);
		}
	}
}
void DriveTrains()
{
	Vector3 PlayerCoords = GET_ENTITY_COORDS(PLAYER_PED_ID(), true);
	Train Train = GET_CLOSEST_VEHICLE(PlayerCoords.x, PlayerCoords.y, PlayerCoords.z, 100.00, GET_HASH_KEY("freight"), 70);
	
	if (DOES_ENTITY_EXIST(Train))
	{
		PrintBottomLeft("Train Found");
		if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_AXIS_Y)){
			SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), Train, -1);
		}
	}
}
void RainBowCar()
{
	int RandomColorType = GET_RANDOM_INT_IN_RANGE(1, 3);
	if (RandomColorType == 1){
		if (pRedMinus){
			if (rpRed == 0){ pRedMinus = false; }
			rpRed = rpRed - 1;
		}
		else
		{
			if (rpRed == 255){ pRedMinus = true; }
			rpRed = rpRed + 1;
		}
		if (sRedMinus){
			if (rsRed == 0){ sRedMinus = false; }
			rsRed = rsRed - 1;
		}
		else
		{
			if (rsRed == 255){ sRedMinus = true; }
			rsRed = rsRed +1;
		}
		rsRed = rsRed + 1;
		SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), rpRed, rpGreen, rpBlue);
		SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), rsRed, rsGreen, rsBlue);
	}

	else if (RandomColorType == 2){
		if (pGreenMinus){
			if (rpGreen == 0){ pGreenMinus = false; }
			rpGreen = rpGreen - 1;
		}
		else
		{
			if (rpGreen == 255){ pGreenMinus = true; }
			rpGreen = rpGreen + 1;
		}
		if (sGreenMinus){
			if (rsGreen == 0){ sGreenMinus = false; }
			rsGreen = rsGreen - 1;
		}
		else
		{
			if (rsGreen == 255){ sGreenMinus = true; }
			rsGreen = rsGreen + 1;
		}
		SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), rpRed, rpGreen, rpBlue);
		SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), rsRed, rsGreen, rsBlue);
	}
	else if (RandomColorType == 3){
		if (pBlueMinus){
			if (rpBlue == 0){ pBlueMinus = false; }
			rpBlue = rpBlue - 1;
		}
		else
		{
			if (rpBlue == 255){ pBlueMinus = true; }
			rpBlue = rpBlue + 1;
		}
		if (sBlueMinus){
			if (rsBlue == 0){ sBlueMinus = false; }
			rsBlue = rsBlue - 1;
		}
		else
		{
			if (rsGreen == 255){ sBlueMinus = true; }
			rsBlue = rsBlue + 1;
		}
		SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), rpRed, rpGreen, rpBlue);
		SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), rsRed, rsGreen, rsBlue);
	}
}
void SaveVehicle()
{
	for (int i = 0; i < 1000; i++)
	{
		if (!VehSaved[i]){
			SavedVehName[i] = GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(GET_ENTITY_MODEL(myVeh));
			SavedVehModel[i] = GET_ENTITY_MODEL(myVeh);
			GET_VEHICLE_COLOURS(myVeh, &SavedVehColor1[i], &SavedVehColor2[i]);
			GET_VEHICLE_CUSTOM_PRIMARY_COLOUR(myVeh, &SavedVehColorPR[i], &SavedVehColorPB[i], &SavedVehColorPG[i]);
			GET_VEHICLE_CUSTOM_SECONDARY_COLOUR(myVeh, &SavedVehColorSR[i], &SavedVehColorSB[i], &SavedVehColorSG[i]);
			for (int m = 0; m < 100; m++)
				SavedVehMods[i][m] = GET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), m);
			VehSaved[i] = 1;
			i = 1001;
		}
	}

	
}
void AddAnim(char* text, char* animDictionary, char* animName)
{
	bool PlayAnim = 0;
	AddOption(text, PlayAnim);
	if (menu::printingop == menu::currentop)
	{
		if (PlayAnim)
		{
			CLEAR_PED_TASKS_IMMEDIATELY(PLAYER_PED_ID());
			REQUEST_ANIM_DICT(animDictionary);
			while (!HAS_ANIM_DICT_LOADED(animDictionary)) WAIT(0);
			{
				TASK_PLAY_ANIM(PLAYER_PED_ID(), animDictionary, animName, 8.0f, 1.0f, -1, 2, 0, 0, 0, 0);
			}
		}
	}

}
void AddScenario(char* text, char* scenarioName)
{
	bool PlayScenario = 0;
	AddOption(text, PlayScenario);
	if (menu::printingop == menu::currentop)
	{
		if (PlayScenario){
			CLEAR_PED_TASKS_IMMEDIATELY(PLAYER_PED_ID());
			TASK_START_SCENARIO_IN_PLACE(PLAYER_PED_ID(), scenarioName, 0, false);
		}
	}
}
void CreateObjectInSlot(char* object)
{
	Vector3 coords = GET_ENTITY_COORDS(PLAYER_PED_ID(), false);
	REQUEST_MODEL(GET_HASH_KEY(object));
	while (!HAS_MODEL_LOADED(GET_HASH_KEY(object))) WAIT(5);
	{
		for (int i = 0; i < ObjectSpawnerslots; i++)
			if (!ObjectSlotUsed[i])
			{
				ObjectSlots[i] = CREATE_OBJECT(GET_HASH_KEY(object), coords.x + 10.0f, coords.y, coords.z, 0.0, 1, 1);
				ObjectSlotsName[i] = object;
				PrintBottomLeft(AddStrings(object, " spawned"));
				ObjectSlotUsed[i] = 1;
				i = ObjectSpawnerslots + 1;
			}
	}
}
void _AddObjectOption(int Object)
{
	if (ObjectSlotUsed[Object])
	{
		null = 0;
		AddOption(ObjectSlotsName[Object], null, nullFunc, SUB::OBJECT);
		if (menu::printingop == menu::currentop)
		{
			if (null) { ObjectSlot = ObjectSlots[Object]; ObjecSlotName = ObjectSlotsName[Object]; SelectedObject = Object; }
		}
	}
	else AddOption("Free Slot");
}
void SupermanManual()
{
	if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_RS)){ APPLY_FORCE_TO_ENTITY(PLAYER_PED_ID(), 1, 0, 200.0f, 0, 0, 0, 0, false, true, false, false, false, true); }
	if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_LS)){ APPLY_FORCE_TO_ENTITY(PLAYER_PED_ID(), 1, 0, -200.0f, 0, 0, 0, 0, false, true, false, false, false, true); }
	if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_ACCEPT)){ APPLY_FORCE_TO_ENTITY(PLAYER_PED_ID(), 1, 0, 0, 50.0F, 0, 0, 0, false, true, false, false, false, true); }
}
void SpeedoMeter()
{
	if (!IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), 0)) return;
	SET_TEXT_FONT(0);
	SET_TEXT_SCALE(0, 0.9f);
	SET_TEXT_CENTRE(0);
	drawstring(AddStrings(Convert::ToString(GET_ENTITY_SPEED(myVeh)*3.6), " KM/h"), 0.8725, 0.8481);
}
void AddComponentSub(char* text, int componentId)
{
	bool OpenSub = 0;
	AddOption(text, OpenSub, nullFunc, SUB::COMPONENTCHANGER);
	if (menu::printingop == menu::currentop)
	{
		if (OpenSub)
		{
			componentChangerId = componentId;
			componentChangerdrawableId = GET_PED_DRAWABLE_VARIATION(PLAYER_PED_ID(), componentId);
			componentChangerTextureId = GET_PED_TEXTURE_VARIATION(PLAYER_PED_ID(), componentId);
			componentChangerCompmentName = text;
		}
	}
}
void AddCompomentPropSub(char* text, int componentId)
{
	bool OpenSub = 0;
	AddOption(text, OpenSub, nullFunc, SUB::COMPONENTCHANGERPROP);
	if (OpenSub){
		componentChangerId = componentId;
		componentChangerdrawableId = GET_PED_PROP_INDEX(PLAYER_PED_ID(), componentId);
		componentChangerTextureId = GET_PED_PROP_TEXTURE_INDEX(PLAYER_PED_ID(), componentId);
		componentChangerCompmentName = text;
	}
}
void AddPedMenu(int SlotNum)
{
	if (PedSlotUsed[SlotNum])
	{
		bool OpenSub = 0;
		AddOption(PedNameSlot[SlotNum], OpenSub, nullFunc, SUB::PED);
		if (menu::printingop == menu::currentop)
		{
			if (OpenSub)
			{
				PED1 = PedSlots[SlotNum];
				NameSlot = PedNameSlot[SlotNum];
				SelectedPedSlot = SlotNum;
				FREEZE_ENTITY_POSITION(PED1, false);
				FreezePed = false;
			}
		}
	}
	else AddOption("Free Slot");
}
void FreeCamLoop()
{
	Vector3 coords = GET_ENTITY_COORDS(PLAYER_PED_ID(), true);
	CLEAR_PED_TASKS_IMMEDIATELY(PLAYER_PED_ID());
    SET_ENTITY_VISIBLE(PLAYER_PED_ID(), 0);
	FREEZE_ENTITY_POSITION(PLAYER_PED_ID(), 1);
	if (IsKeyDown(VK_NUMPAD8)){ coords.x++; SET_ENTITY_COORDS(PLAYER_PED_ID(), coords.x, coords.y, coords.z, true, true, true, true); }
	else if (IsKeyDown(VK_NUMPAD2)){ coords.x--; SET_ENTITY_COORDS(PLAYER_PED_ID(), coords.x, coords.y, coords.z, true, true, true, true); }
	else if (IsKeyDown(VK_NUMPAD6)){ coords.y++; SET_ENTITY_COORDS(PLAYER_PED_ID(), coords.x, coords.y, coords.z, true, true, true, true); }
	else if (IsKeyDown(VK_NUMPAD4)){ coords.y--; SET_ENTITY_COORDS(PLAYER_PED_ID(), coords.x, coords.y, coords.z, true, true, true, true); }
	else if (IsKeyDown(VK_NUMPAD7)){ coords.z++; SET_ENTITY_COORDS(PLAYER_PED_ID(), coords.x, coords.y, coords.z, true, true, true, true); }
	else if (IsKeyDown(VK_NUMPAD1)){ coords.z = coords.z - 1; SET_ENTITY_COORDS(PLAYER_PED_ID(), coords.x, coords.y, coords.z, true, true, true, true); }
}
bool MTaxiCreated = 0;
void MilitaryTaxi()
{
	if (!MTaxiCreated){
		RequestModel(GET_HASH_KEY("insurgent"));
		Vector3 Road1, Road2, PlayerCoords = GET_ENTITY_COORDS(PLAYER_PED_ID(), true);
		GET_CLOSEST_ROAD(PlayerCoords.x, PlayerCoords.y, PlayerCoords.z, 1.0f, 1, &Road1.x, &Road2.x, &Road1.z, &Road1.y, &Road2.y, false);
		CREATE_VEHICLE(GET_HASH_KEY("insurgnt"), Road1.x, Road1.y, Road1.z, 0.0f, 1, 1);
		RequestModel(GET_HASH_KEY("u_m_y_militarybum"));

	}
	

}
void set_gta2_cam_rot()
{
	Vector3 Rot = GET_GAMEPLAY_CAM_ROT(2);
	if (!Check_self_in_vehicle()){
		SET_ENTITY_ROTATION(PLAYER_PED_ID(), Rot.x, Rot.y, Rot.z, 2, 1);
	}
	else{
		SET_ENTITY_ROTATION(myVeh, Rot.x, Rot.y, Rot.z, 2, 1);
	}
}
void AddPedWeapon(char* Text, int Weapon)
{
	bool Apply = 0;
	AddOption(Text, Apply);
	if (PedSpawnWithWeapon[Weapon]){
		if (OptionY < 0.6325 && OptionY > 0.1425)
		{
			DRAW_SPRITE("commonmenu", "shop_tick_icon", 0.233f + menuPos, 0.015f + OptionY, 0.036f, 0.036f, 0.0f, 255, 255, 255, 255);
		}
	}
	if (menu::printingop == menu::currentop)
	{
		if (Apply){
			if (!PedSpawnWithWeapon[Weapon]) PedSpawnWithWeapon[Weapon] = 1;
			else PedSpawnWithWeapon[Weapon] = 0;
		}
	}
}
void SetPlayerModel(char* model)
{
	Hash modelHash = GET_HASH_KEY(model);
	int weaponModelsSize = getArraySize(Array::WeaponModels);
	bool tmpWeapons[57];
	if (IS_MODEL_IN_CDIMAGE(modelHash))
	{
		for (int i = 0; i < weaponModelsSize; i++)
			if (HAS_PED_GOT_WEAPON(PLAYER_PED_ID(), GET_HASH_KEY(getFromArray(Array::WeaponModels, i)), FALSE)) tmpWeapons[i] = 1;
		REQUEST_MODEL(modelHash);
		while (!HAS_MODEL_LOADED(modelHash)) WAIT(0);
		SET_PLAYER_MODEL(PLAYER_ID(), modelHash);
		SET_MODEL_AS_NO_LONGER_NEEDED(modelHash);
		for (int i = 0; i < weaponModelsSize; i++)
			if (tmpWeapons[i]){ GIVE_DELAYED_WEAPON_TO_PED(PLAYER_PED_ID(), GET_HASH_KEY(getFromArray(Array::WeaponModels, i)), 9999, 1); tmpWeapons[i] = 0; }
	}
	else PrintBottomLeft("~r~Error: Invalid ~s~Model");

}
void _DrawFps(float x, float y, char* a_2, float value, int decimals)
{
		_SET_TEXT_ENTRY(a_2);
		ADD_TEXT_COMPONENT_FLOAT(value, decimals);
		_DRAW_TEXT(x, y);
}
int fps;
int l_2B = 0, v_3 = 0;
Float10 l_2C;
float v_2 = 0.0;
void DrawFps()
{
	l_2C =  _0xE599A503B3837E1B();
	l_2B += 1;
	if (l_2B == 10) {
	    v_2 += l_2C._0;
		v_2 += l_2C._1;
		v_2 += l_2C._2;
		v_2 += l_2C._3;
		v_2 += l_2C._4;
		v_2 += l_2C._5;
		v_2 += l_2C._6;
		v_2 += l_2C._7;
		v_2 += l_2C._8;
		v_2 += l_2C._9;
		v_2 += l_2C._10;
		fps = v_2 / 10.0;
	}
	if (fps > 0.0) {
		SET_TEXT_FONT(0);
		SET_TEXT_SCALE(0, 1.1f);
		SET_TEXT_CENTRE(0);
		drawstring(AddStrings(Convert::ToString(fps), " FPS"), 0.1725, 0.8481);
	}
}
void ModJustLoaded()
{
	ModJustLoadedCheck = 0;
}
void CreateTmpVeh()
{
	if (!tmpvehCreated){
		RequestModel(GET_HASH_KEY("adder"));
		TMPVehicle = CREATE_VEHICLE(GET_HASH_KEY("adder"), 0.0, 0.0, 0.0, 0.0, 0, 0);
		SET_VEHICLE_NUMBER_PLATE_TEXT(TMPVehicle, "TMPVEH");
		FREEZE_ENTITY_POSITION(TMPVehicle, true);
		SET_ENTITY_INVINCIBLE(TMPVehicle, true);
		SET_VEHICLE_MOD_KIT(TMPVehicle, 0);
		tmpvehCreated = 1;
	}
}
void DeleteTmpVeh()
{
	if (tmpvehCreated){
		SET_ENTITY_AS_MISSION_ENTITY(TMPVehicle, 1, 1);
		DELETE_VEHICLE(&TMPVehicle);
		tmpvehCreated = 0;
	}
}
void RainbowNeon()
{
	switch (GET_RANDOM_INT_IN_RANGE(1, 3))
	{
	case 1: if (NeonColor.R >= 255) NeonRMinus = true; else if (NeonColor.R <= 0) NeonRMinus = false;  if (!NeonRMinus) NeonColor.R++; else NeonColor.R--;
	case 2: if (NeonColor.G >= 255) NeonGMinus = true; else if (NeonColor.G <= 0) NeonGMinus = false;  if (!NeonGMinus) NeonColor.G++; else NeonColor.G--;
	case 3: if (NeonColor.B >= 255) NeonBMinus = true; else if (NeonColor.B <= 0) NeonBMinus = false;  if (!NeonBMinus) NeonColor.B++; else NeonColor.B--;
	}
	_SET_VEHICLE_NEON_LIGHTS_COLOUR(myVeh, NeonColor.R, NeonColor.G, NeonColor.B);
}
void DrawCoords()
{
	Vector3 c = GET_ENTITY_COORDS(PLAYER_PED_ID(), 1);
	SET_TEXT_FONT(0);
	SET_TEXT_SCALE(0, 0.7f);
	SET_TEXT_CENTRE(0);
	drawstring(Add3Strings(AddStrings("X: ", Convert::ToString(c.x)), AddStrings(" Y: ", Convert::ToString(c.y)), AddStrings(" Z: ", Convert::ToString(c.z))), 0.3725, 0.8481);
}

void VehColorAnimation()
{
	if (ColorToAnimateTo.R != (int) ColorAnimationColor.r)
	{
		ColorAnimationColor.r += animationSpeed.r;
		ColorAnimationColor.b += animationSpeed.r;
		ColorAnimationColor.g += animationSpeed.r;
		SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(AnimateColorVeh, ColorAnimationColor.r, ColorAnimationColor.g, ColorAnimationColor.b);
		return;
	}
	ColorAnimationRunning = false;
}

void AnimateVehColor(Vehicle vehicle, int r, int g, int b)
{
	if (ColorAnimationRunning) return;
	RGBA currentColor;
	GET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, &currentColor.R, &currentColor.G, &currentColor.B);
	RGBA diffrance = { r - currentColor.R, g - currentColor.G, b - currentColor.B, 0 };
	PrintDebugMessage(AddStrings("Diffrance r is ", Convert::ToString(diffrance.R)));
	ColorToAnimateTo = { r, g, b, 0 };
	ColorAnimationColor = { (float)currentColor.R, (float)currentColor.G, (float)currentColor.B };
	AnimateColorVeh = vehicle;
	ColorAnimationRunning = true;
	animationSpeed = { (float)diffrance.R / 100, (float)diffrance.G / 100, (float)diffrance.B / 100 };
}
void TrainSlowStop()
{
	if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_RB) && IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_LB))
	{
		float TrainSpeed = GET_ENTITY_SPEED(Train1);
		while (TrainSpeed > 0)
		{
			TrainSpeed -= 0.01;
			if (TrainSpeed < 0)
			{
				int wait = 1000;
				while (wait > 0)
				{
					wait--;
					SET_TRAIN_SPEED(Train1, 0);
					WAIT(1);
				}
			}
			SET_TRAIN_SPEED(Train1, TrainSpeed);
			WAIT(0);
		}
	}
}
bool setAsMissionEntity = false;
int missionEntityCounter = 0;
void MissionEntityLoop()
{
	if (!IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), false)) { return;  setAsMissionEntity = false; }
	if (!IS_ENTITY_A_MISSION_ENTITY(myVeh)) 
	{
		if (setAsMissionEntity) 
		{
			PrintDebugMessage("~r~Vehicle set as a mission entity by another script");
			missionEntityCounter++;
			if (missionEntityCounter == 10)
			{
				PrintDebugMessage("Vehicle has been set as a mission entity by another script ~r~10 times");
			}
		}
		SET_ENTITY_AS_MISSION_ENTITY(myVeh, true, true);
		PrintDebugMessage("Veh set as mission entity");
		setAsMissionEntity = true;
	}
}
void CrashAvoidMain()
{
	if (!IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), false)) return;
	Vector3 pVehCoords = GET_ENTITY_COORDS(myVeh, true);
	Vehicle nearVeh = GET_CLOSEST_VEHICLE(pVehCoords.x, pVehCoords.y, pVehCoords.z, 10.0f, 0, 70);
	if (!DOES_ENTITY_EXIST(nearVeh)) return;
	Vector3 nVehCoords = GET_WORLD_POSITION_OF_ENTITY_BONE(nearVeh, GET_ENTITY_BONE_INDEX_BY_NAME(nearVeh, "windscreen"));
	PrintDebugMessage(AddStrings("Distance to near = ", Convert::ToString(GET_DISTANCE_BETWEEN_COORDS(nVehCoords.x, nVehCoords.y, nVehCoords.z, pVehCoords.x, pVehCoords.y, pVehCoords.z, false))));
	if (GET_DISTANCE_BETWEEN_COORDS(nVehCoords.x, nVehCoords.y, nVehCoords.z, pVehCoords.x, pVehCoords.y, pVehCoords.z, false) < 1)
	{
		PrintDebugMessage("Crash Avoided");
		SET_VEHICLE_FORWARD_SPEED(myVeh, -1);
	}
}


}



namespace sub{
// Define submenus here.

void MainMenu()
{
	AddTitle("Main Menu");
	AddOption("Online Players", null, nullFunc, SUB::ONLINEPLAYERS);
	AddOption("Player", null, nullFunc, SUB::PLAYER);
	//AddOption("Model Changer", null, nullFunc, SUB::MODELCHANGER);
	AddOption("Vehicle", null, nullFunc, SUB::VEHICLE1);
	//AddOption("Vehicle Spawner", null, nullFunc, SUB::VEHICLESPAWNER);
	AddOption("Ped Spawner", null, nullFunc, SUB::PEDSPAWNER);
	AddOption("Weapons", null, nullFunc, SUB::WEAPONS);
	AddOption("Teleport", null, nullFunc, SUB::TELEPORT);
	AddOption("Object Spawner", null, nullFunc, SUB::OBJECTSPAWNER);
	AddOption("Ipl Loader", null, nullFunc, SUB::IPLLOADER);
	AddOption("Weather", null, nullFunc, SUB::WEATHER);
	AddOption("Misc", null, nullFunc, SUB::MISC);
	AddOption("Settings", null, nullFunc, SUB::SETTINGS);
	
	//char* PlayerName = NETWORK_PLAYER_GET_NAME2(0);

	if (menujustopened)
	{
		PrintBottomLeft(AddStrings("~g~Welcome ", NETWORK_PLAYER_GET_NAME2(0))); // Your opening message goes here.
		menujustopened = false;
	}
}

void Settings()
{
	bool settings_pos_plus = 0, settings_pos_minus = 0;

	AddTitle("Settings");
	AddOption("Menu Colours", null, nullFunc, SUB::SETTINGS_COLOURS);
	AddOption("Menu Fonts", null, nullFunc, SUB::SETTINGS_FONTS);
	AddToggle("Centre Title", menu::bit_centre_title);
	AddToggle("Centre Options", menu::bit_centre_options);
	AddToggle("Centre Breaks", menu::bit_centre_breaks);
	AddToggle("Gradients", gradients);
	AddToggle("Debug", DebugMode);
	AddToggle("Bete features", BetaFeatures);
	AddNumber("Menu Position", menuPos * 145.985401459854, 0, null, settings_pos_plus, settings_pos_minus);

	if (settings_pos_plus){
		if (menuPos < 0.68f) menuPos += 0.01f;
		return;
	}
	else if (settings_pos_minus){
		if (menuPos > 0.0f) menuPos -= 0.01f;
		return;
	}

	if (menuPos < 0){ menuPos = 0; }
	
}
void AddsettingscolOption(char* text, RGBA &feature)
{
	AddOption(text, null, nullFunc, SUB::SETTINGS_COLOURS2);

	if (menu::printingop == menu::currentop) settings_rgba = &feature;
}
void SettingsColours()
{
	AddTitle("Menu Colours");
	AddsettingscolOption("Title Box", titlebox);
	AddsettingscolOption("Background", BG);
	AddsettingscolOption("Title Text", titletext);
	AddsettingscolOption("Option Text", optiontext);
	AddsettingscolOption("Selected Text", selectedtext);
	AddsettingscolOption("Option Breaks", optionbreaks);
	AddsettingscolOption("Option Count", optioncount);
	AddsettingscolOption("Selection Box", selectionhi);
	AddToggle("Rainbow", loop_RainbowBoxes);
}
void SettingsColours2()
{
	bool settings_r_input = 0, settings_r_plus = 0, settings_r_minus = 0;
	int *settings_rgba2;

	AddTitle("Set Colour");
	AddNumber("Red", settings_rgba->R, 0, DisplayKeyboard, settings_r_plus, settings_r_minus);
	AddNumber("Green", settings_rgba->G, 0, DisplayKeyboard, settings_r_plus, settings_r_minus);
	AddNumber("Blue", settings_rgba->B, 0, DisplayKeyboard, settings_r_plus, settings_r_minus);
	AddNumber("Opacity", settings_rgba->A, 0, DisplayKeyboard, settings_r_plus, settings_r_minus);

	switch (menu::currentop)
	{
	case 1: settings_rgba2 = &settings_rgba->R; break;
	case 2: settings_rgba2 = &settings_rgba->G; break;
	case 3: settings_rgba2 = &settings_rgba->B; break;
	case 4: settings_rgba2 = &settings_rgba->A; break;
	}

	if (DisplayKeyboard){
		if (!OnscreenKeyboardDisplayed){ DISPLAY_ONSCREEN_KEYBOARD(false, "", "", "", "", "", "", 100); OnscreenKeyboardDisplayed = 1; }
		if (UPDATE_ONSCREEN_KEYBOARD() == 1){
			DisplayKeyboard = 0; OnscreenKeyboardDisplayed = 0;
			int tempHash;
		    STRING_TO_INT(GET_ONSCREEN_KEYBOARD_RESULT(), &tempHash);
			if (!(tempHash >= 0 && tempHash <= 255)) PrintError_InvalidInput();
			else *settings_rgba2 = tempHash;
			return;
		}
		else if (UPDATE_ONSCREEN_KEYBOARD() == 2){ DisplayKeyboard = 0; OnscreenKeyboardDisplayed = 0; PrintBottomLeft("~r~Canceled"); }
		else if (UPDATE_ONSCREEN_KEYBOARD() == 3){ DisplayKeyboard = 0; OnscreenKeyboardDisplayed = 0; PrintBottomLeft("~r~ ERROR: ~s~Unknown keyboard error"); }
	}

	if (settings_r_plus){
		if (*settings_rgba2 < 255) (*settings_rgba2)++;
		else *settings_rgba2 = 0;
		return;
	}
	else if (settings_r_minus){
		if (*settings_rgba2 > 0) (*settings_rgba2)--;
		else *settings_rgba2 = 255;
		return;
	}
}
void AddsettingsfonOption(char* text, int font_index = -1, int &feature = inull)
{
	bool bit_changefont = 0, bit_setfeature = 0;
	if (font_index == -1) AddOption(text, bit_setfeature, nullFunc, SUB::SETTINGS_FONTS2);
	else AddOption(text, bit_changefont);

	if (bit_setfeature) settings_font = &feature;
	else if (bit_changefont) *settings_font = font_index;
}
void SettingsFonts()
{
	AddTitle("Menu Fonts");
	AddsettingsfonOption("Title", -1, font_title);
	AddsettingsfonOption("Options", -1, font_options);
	AddsettingsfonOption("Selected Option", -1, font_selection);
	AddsettingsfonOption("Option Breaks", -1, font_breaks);
}
void SettingsFonts2()
{
	bool fonts2_input = 0;

	AddTitle("Set Font");
	AddsettingsfonOption("Normalish", 0);
	AddsettingsfonOption("Impactish", 4);
	AddsettingsfonOption("Italic", 1);
	AddsettingsfonOption("Pricedown", 7);
	AddsettingsfonOption("Caps", 2);
	AddKeyboard("Input Index", fonts2_input);

	if (fonts2_input){
		int tempInt;
		STRING_TO_INT(GET_ONSCREEN_KEYBOARD_RESULT(), &tempInt);
		*settings_font = tempInt;
		return;
	}
}



void SampleSub()
{
	bool sample_mapmod = 0, hour_plus = 0, hour_minus = 0, timescale_plus = 0, timescale_minus = 0, sample_invisible = 0, sample_gravity_gun_on = 0,
	sample_gta2cam = 0;

	int sample_hour = GET_CLOCK_HOURS();

	AddTitle("SHRUNKEN TITLE FEATURE");

	AddBreak("---Map---");
	AddOption("Load Map Mod", sample_mapmod);
	AddTele("Teleport to Map Mod", 509.8423f, 5589.2422f, 792.0000f);

	AddBreak("---Weather---");
	AddNumber("Hour", GET_CLOCK_HOURS(), 0, null, hour_plus, hour_minus);
	AddNumber("Time Scale", current_timescale, 2, null, timescale_plus, timescale_minus);

	AddBreak("---Others---");
	AddLocal("Invisibility", !IS_ENTITY_VISIBLE(PLAYER_PED_ID()), sample_invisible, sample_invisible);
	AddToggle("Gravity Gun", loop_gravity_gun, sample_gravity_gun_on);
	AddToggle("GTA 2 Cam", loop_gta2cam, sample_gta2cam, sample_gta2cam);
	AddToggle("Massacre Mode", loop_massacre_mode);
	AddOption("Create Escort", null, sample_createEscort);

	AddBreak("---deez breaks r ugly---");


	if (sample_mapmod){
		Any tempHash = GET_HASH_KEY("prop_container_01a");
		PlaceObject(tempHash, 509.8423f, 5589.2422f, 791.0656f, 0.1410f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 520.5002f, 5584.3774f, 790.5033f, 5.4410f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 531.0571f, 5579.5405f, 788.6912f, 12.4410f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 541.3253f, 5574.8403f, 785.4896f, 19.4409f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 551.0662f, 5570.3701f, 780.7990f, 27.5407f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 560.1738f, 5566.2046f, 774.6979f, 35.0403f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 568.6718f, 5562.3198f, 767.4281f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 576.9716f, 5558.5269f, 759.5663f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 585.2493f, 5554.7471f, 751.7451f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 593.5072f, 5550.9722f, 743.9170f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 601.7770f, 5547.1912f, 736.0764f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 610.0651f, 5543.3994f, 728.2167f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 618.3337f, 5539.6226f, 720.3861f, 40.7936f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 626.6017f, 5535.8477f, 712.5473f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 634.8616f, 5532.0669f, 704.7252f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 643.1213f, 5528.2861f, 696.8940f, 40.7936f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 651.3914f, 5524.5059f, 689.0526f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 659.6512f, 5520.7275f, 681.2211f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 667.9110f, 5516.9424f, 673.3893f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 676.1708f, 5513.1670f, 665.5580f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 684.4307f, 5509.3789f, 657.7266f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 692.6906f, 5505.6079f, 649.9052f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 700.9504f, 5501.8271f, 642.0737f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 709.2201f, 5498.0464f, 634.2426f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 717.4602f, 5494.2759f, 626.4309f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 725.7202f, 5490.4980f, 618.5996f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 733.9800f, 5486.7226f, 610.7783f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 742.5997f, 5482.7764f, 603.1669f, 36.9395f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 751.8304f, 5478.5518f, 596.3347f, 31.0392f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 761.7103f, 5474.0220f, 590.6132f, 24.5989f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 772.0702f, 5469.2827f, 586.0803f, 18.9288f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 782.8400f, 5464.3433f, 582.8604f, 11.5788f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 793.8899f, 5459.2847f, 581.1174f, 5.0787f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 805.1001f, 5454.1479f, 580.8762f, -2.5212f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 816.1702f, 5449.0796f, 581.9746f, -7.6213f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 827.1907f, 5444.0405f, 584.5823f, -16.6212f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 837.6807f, 5439.2407f, 588.8990f, -24.4210f, 0.0f, 65.3998f);
		PrintBottomLeft(AddStrings("Hax by ~b~", "XBLToothpik"));
		return;
	}

	if (hour_plus){
		if (sample_hour + 1 == 24) NETWORK_OVERRIDE_CLOCK_TIME(0, 0, 0);
		else NETWORK_OVERRIDE_CLOCK_TIME((sample_hour + 1), 0, 0);
		return;
	}
	else if (hour_minus){
		if ((sample_hour - 1) == -1) NETWORK_OVERRIDE_CLOCK_TIME(23, 0, 0);
		else NETWORK_OVERRIDE_CLOCK_TIME((sample_hour - 1), 0, 0);
		return;
	}

	if (timescale_plus){
		if (current_timescale < 2.0f) current_timescale += 0.1f;
		SET_TIME_SCALE(current_timescale);
		return;
	}
	else if (timescale_minus){
		if (current_timescale > 0.0f) current_timescale -= 0.1f;
		SET_TIME_SCALE(current_timescale);
		return;
	}

	if (sample_invisible){
		if (IS_ENTITY_VISIBLE(PLAYER_PED_ID())) SET_ENTITY_VISIBLE(PLAYER_PED_ID(), 0);
		else SET_ENTITY_VISIBLE(PLAYER_PED_ID(), 1);
		return;
	}

	if (sample_gravity_gun_on){
		PrintStringBottomCentre("Use Mr ~b~Pistol~s~ for Hax!");
		return;
	}

	if (sample_gta2cam){
		if (loop_gta2cam)
		{
			if (DOES_CAM_EXIST(cam_gta2)) SET_CAM_ACTIVE(cam_gta2, 1);
			else
			{
				cam_gta2 = CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", 1);
				ATTACH_CAM_TO_ENTITY(cam_gta2, PLAYER_PED_ID(), 0.0f, 0.0f, 8.5f, 1);
				Vector3 Pos = GET_ENTITY_COORDS(PLAYER_PED_ID(), 1);
				POINT_CAM_AT_COORD(cam_gta2, Pos.x, Pos.y, -1000000);
				SET_CAM_ACTIVE(cam_gta2, 1);
			}
			RENDER_SCRIPT_CAMS(1, 0, 3000, 1, 0);
		}
		else if (DOES_CAM_EXIST(cam_gta2))
			{
				SET_CAM_ACTIVE(cam_gta2, 0);
				DESTROY_CAM(cam_gta2, 0);
				RENDER_SCRIPT_CAMS(0, 0, 3000, 1, 0);
			}
		return;
	}



}

void YourSub()

{
	// Initialise local variables here:
	bool print_deez_nuts = 0, player_godmode = 0;

	// Options' text here:
	AddTitle("Main");
	AddOption("option 1", print_deez_nuts);
	AddOption("Option 2", print_deez_nuts);
	AddOption("Option 3", print_deez_nuts);
	AddOption("Option 4", print_deez_nuts);
	AddOption("Option 5", print_deez_nuts);
	AddOption("Option 6", print_deez_nuts);
	AddOption("Option 7", print_deez_nuts);
	AddOption("Option 8", print_deez_nuts);
	AddOption("Option 9", print_deez_nuts);
	AddOption("Option 10", print_deez_nuts);
	AddOption("Option 11", print_deez_nuts);
	AddOption("Option 12", print_deez_nuts);
	AddOption("Option 13", print_deez_nuts);
	AddOption("Option 14", print_deez_nuts);
	AddOption("Option 15", print_deez_nuts);
	AddOption("Option 16", print_deez_nuts);
	AddOption("Option 17", print_deez_nuts);
	AddOption("Option 18", print_deez_nuts);
	AddOption("Option 19", print_deez_nuts);
	AddOption("Option 20", print_deez_nuts);
	AddOption("Option 21", print_deez_nuts);
	AddOption("Option 22", print_deez_nuts);
	AddOption("Option 23", print_deez_nuts);
	AddOption("Option 24", print_deez_nuts);
	AddOption("Option 25", print_deez_nuts);
	AddOption("Option 26", print_deez_nuts);
	AddOption("Option 27", print_deez_nuts);
	AddOption("Option 28", print_deez_nuts);
	AddOption("Option 29", print_deez_nuts);
	AddOption("Option 30", print_deez_nuts);
	AddOption("Option 31", print_deez_nuts);
	AddOption("Option 32", print_deez_nuts);

	// Options' code here:
	if (print_deez_nuts)
	{
		PrintStringBottomCentre(Add3Strings("Option ", Convert::ToString(menu::currentop) , " ~b~selected!" ));
		return; // Either use return; to exit to the switch if you don't have code below that you want executed.
	}


}
void AddOnlinePlayer(int id)
{
	bool OpenSub = 0;
	AddOption(NETWORK_PLAYER_GET_NAME2(id), OpenSub, nullFunc, SUB::ONLINEPLAYER);
	if (OpenSub) selectedPlayer = id;
}
void OnlinePlayers()
{
	AddTitle("Online Players");
	AddOption("All Players", null, nullFunc, SUB::ALLPLAYERS);
	for (int i = 0; i < 31; i++)
		AddOnlinePlayer(i);
}
void OnlinePlayer()

{
	bool teleport_to_player = 0, explodeplayer = 0, giveallweapons = 0, takeall = 0, kick = 0, attach = 0, teleport_into_vehicle = 0, detach = 0, crashGame = 0;

	char* PLAYERNAME = NETWORK_PLAYER_GET_NAME2(selectedPlayer);

	AddTitle(PLAYERNAME);
	AddOption("Teleport to player", teleport_to_player);
	AddOption("Teleport into Vehicle", teleport_into_vehicle);
	AddOption("Attach to player", attach);
	AddOption("Detach from player", detach);
	AddOption("Give all Weapons", giveallweapons);
	AddOption("Take All Weapons", takeall);
	AddToggle("Cash Drop", cash_check);
	AddOption("Explode", explodeplayer);
	AddOption("Kick", kick);
	AddOption("Crash Game(Does not workÞ!!)", crashGame);
	AddOption("Blame Player", null, nullFunc, SUB::ONLINEBLAMEPLAYER);
	AddOption("Vehicle Options", null, nullFunc, SUB::ONLINEVEHICLE);

	if (teleport_to_player){
		if (IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), false))
		{
			Vector3 PLAYERPOS = GET_ENTITY_COORDS(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), true);
			SET_ENTITY_COORDS(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), PLAYERPOS.x, PLAYERPOS.y, PLAYERPOS.z, 0, 0, 0, 1);
			PrintStringBottomCentre(AddStrings("Teleported to ", PLAYERNAME));
		}
		else
		{
			Vector3 PLAYERPOS = GET_ENTITY_COORDS(GET_PLAYER_PED(selectedPlayer), true);
			SET_ENTITY_COORDS(PLAYER_PED_ID(), PLAYERPOS.x, PLAYERPOS.y, PLAYERPOS.z, 0, 0, 0, 1);
			PrintStringBottomCentre(AddStrings("Teleported to ", PLAYERNAME));
		}
		return;
	}

	if (teleport_into_vehicle){
		if (IS_PED_IN_ANY_VEHICLE(GET_PLAYER_PED(selectedPlayer), false))
		{
			Vector3 PLAYERPOS = GET_ENTITY_COORDS(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), true);
			SET_ENTITY_COORDS(PLAYER_PED_ID(), PLAYERPOS.x, PLAYERPOS.y, PLAYERPOS.z, 0, 0, 0, 1);
			SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), -2);
		}
		else
			PrintStringBottomCentre(AddStrings(PLAYERNAME, " isn't in vehicle"));
	}
	if (attach){
		if (selectedPlayer == 0)
		{
			PrintStringBottomCentre("~r~YOU CAN'T ATTACH TO YOURSELF!!!");
		}
		else
		{
			ATTACH_ENTITY_TO_ENTITY(PLAYER_PED_ID(), GET_PLAYER_PED(selectedPlayer), -1, 0, -0.3, 0, 0, 0, 0, false, false, true, false, 2, true);
			PrintStringBottomCentre(AddStrings("Attached to ", PLAYERNAME));
		}
		return;
	}

	if (explodeplayer){
		Vector3 coords = GET_ENTITY_COORDS(GET_PLAYER_PED(selectedPlayer), true);
		ADD_EXPLOSION(coords.x, coords.y, coords.z, 26, 4.0f, 1, 0, 3.0f);
		return;
	}

	if (giveallweapons){
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0xa2719263, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x99b507ea, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x678b81b1, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x4e875f73, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x958a4a8f, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x440e4788, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x84bd7bfd, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x1b06d571, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x5ef9fec4, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x22d8fe39, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x99aeeb3b, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x13532244, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x2be6766b, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0xefe7e2df, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0xbfefff6d, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x83bf0278, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0xaf113f99, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x9d07f764, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x7fd62962, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x1d073a89, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x7846a318, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0xe284c527, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x9d61e50f, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x3656c8c1, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x5fc3c11, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0xc472fe2, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0xa284510b, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x4dd2dc56, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0xb1ca77b1, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x687652ce, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x42bf8a85, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x93e220bd, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x2c3731d9, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0xfdbc8a50, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0xa0973d5e, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x24b17070, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x60ec506, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x34a67b97, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x23c9f95c, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x497facc3, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0xf9e6aa4b, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x61012683, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0xc0a3098d, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0xd205520e, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0xbfd21232, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x7f229f94, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x92a27487, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x83839c4, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0xa89cb99e, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x7f7497e5, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x3aabbbaa, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0xc734385a, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x63ab0442, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0xaf2208a7, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x787f0bb, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0xF9DCBF2D, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(selectedPlayer), 0x6D544C99, 9999, 1);
		return;
	}

	if (takeall){
		REMOVE_ALL_PED_WEAPONS(GET_PLAYER_PED(selectedPlayer), 1);
		return;
	}

	if (kick){
		NETWORK_SESSION_KICK_PLAYER(selectedPlayer);
		return;
	}

	if (detach){
		DETACH_ENTITY(PLAYER_PED_ID(), true, true);
		return;
	}

	if (crashGame){
		for (int i; i < 30; i++)
			CLONE_PED(GET_PLAYER_PED(selectedPlayer), 0.0, 1, 1);
	}



}
void OnlineVehicle()
{
	bool crappy_engine = 0, boost = 0, super_brake = 0, fully_upgrade = 0, fix = 0, launch = 0, super_boost = 0, freeze = 0, unfreeze = 0;

	AddTitle("Vehicle");
	AddOption("Fix", fix);
	AddOption("Boost", boost);
	AddOption("Super Boost", super_boost);
	AddOption("Super Brake", super_brake);
	AddOption("Fully Upgrade", fully_upgrade);
	AddOption("Install Crappy Engine", crappy_engine);
	AddOption("Launch", launch);
	AddOption("Freeze", freeze);
	AddOption("Unfreeze", unfreeze);

	if (fix){
		NETWORK_REQUEST_CONTROL_OF_ENTITY(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)));
		WAIT(0);
		SET_VEHICLE_FIXED(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)));
		SET_VEHICLE_DIRT_LEVEL(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 0.0f);
		return;
	}

	if (boost){
		NETWORK_REQUEST_CONTROL_OF_ENTITY(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)));
		WAIT(0);
		SET_VEHICLE_FORWARD_SPEED(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 100.0f);
		return;
	}

	if (super_boost){
		NETWORK_REQUEST_CONTROL_OF_ENTITY(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)));
		WAIT(0);
		SET_ENTITY_MAX_SPEED(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 100000);
		SET_VEHICLE_FORWARD_SPEED(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 10000.0f);
		return;
	}

	if (super_brake){
		NETWORK_REQUEST_CONTROL_OF_ENTITY(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)));
		WAIT(0);
		SET_VEHICLE_FORWARD_SPEED(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 0.0f);
		return;
	}

	if (fully_upgrade){
		NETWORK_REQUEST_CONTROL_OF_ENTITY(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)));
		WAIT(0);
		SET_VEHICLE_MOD_KIT(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 0);
		SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 1);
		TOGGLE_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 18, 1);
		TOGGLE_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 22, 1);
		SET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 16, 5, 0);
		SET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 12, 2, 0);
		SET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 11, 3, 0);
		SET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 14, 14, 0);
		SET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 15, 3, 0);
		SET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 13, 2, 0);
		SET_VEHICLE_WHEEL_TYPE(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 6);
		SET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 5);
		SET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 23, 19, 1);
		SET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 0, 1, 0);
		SET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 1, 1, 0);
		SET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 2, 1, 0);
		SET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 3, 1, 0);
		SET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 4, 1, 0);
		SET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 5, 1, 0);
		SET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 6, 1, 0);
		SET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 7, 1, 0);
		SET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 8, 1, 0);
		SET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 9, 1, 0);
		SET_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 10, 1, 0);
		return;
	}

	if (crappy_engine){
		NETWORK_REQUEST_CONTROL_OF_ENTITY(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)));
		WAIT(0);
		_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), -90);
		return;
	}

	if (launch){
		NETWORK_REQUEST_CONTROL_OF_ENTITY(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)));
		SET_ENTITY_MAX_SPEED(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), 10000);
		WAIT(0);
		APPLY_FORCE_TO_ENTITY(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), true, 0, 0, 9999999999999, 0, 0, 0, true, true, true, true, false, true);
		return;
	}

	if (freeze){
		NETWORK_REQUEST_CONTROL_OF_ENTITY(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)));
		WAIT(0);
		FREEZE_ENTITY_POSITION(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), true);
		return;
	}

	if (unfreeze){
		NETWORK_REQUEST_CONTROL_OF_ENTITY(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)));
		WAIT(0);
		FREEZE_ENTITY_POSITION(GET_VEHICLE_PED_IS_USING(GET_PLAYER_PED(selectedPlayer)), false);
		return;
	}
}
void AddBlamePlayer(int playerIndex)
{
	bool Blame = 0;
	AddOption(GET_PLAYER_NAME(playerIndex), Blame);
	if (menu::printingop == menu::currentop)
	{
		if (Blame){
			Vector3 coords = GET_ENTITY_COORDS(GET_PLAYER_PED(playerIndex), true);
			ADD_OWNED_EXPLOSION(GET_PLAYER_PED(playerIndex), coords.x, coords.y, coords.z, 26, 4.0f, 1, 0, 3.0f);
		}
	}
}
void OnlineBlamePlayer()
{
	AddTitle("Blame player");
	AddBlamePlayer(0);
	AddBlamePlayer(1);
	AddBlamePlayer(2);
	AddBlamePlayer(4);
	AddBlamePlayer(5);
	AddBlamePlayer(6);
	AddBlamePlayer(7);
	AddBlamePlayer(8);
	AddBlamePlayer(9);
	AddBlamePlayer(10);
	AddBlamePlayer(11);
	AddBlamePlayer(12);
	AddBlamePlayer(13);
	AddBlamePlayer(14);
	AddBlamePlayer(15);
	AddBlamePlayer(16);
	AddBlamePlayer(17);
	AddBlamePlayer(18);
	AddBlamePlayer(19);
	AddBlamePlayer(20);
	AddBlamePlayer(21);
	AddBlamePlayer(22);
	AddBlamePlayer(23);
	AddBlamePlayer(24);
	AddBlamePlayer(25);
	AddBlamePlayer(26);
	AddBlamePlayer(27);
	AddBlamePlayer(28);
	AddBlamePlayer(29);
	AddBlamePlayer(30);
	AddBlamePlayer(31);
}
void allplayers()

{
	bool giveallweaponsonline = 0, TakeAllWeapons = 0, ExplodeAll = 0;

	AddTitle("All Players");
	AddOption("Give All Weapons", giveallweaponsonline);
	AddOption("Take All Weapons", TakeAllWeapons);
	AddOption("Explode all", ExplodeAll);

	if (giveallweaponsonline){
		for (int i = 1; i < 31; i++)
		{
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0xa2719263, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x99b507ea, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x678b81b1, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x4e875f73, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x958a4a8f, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x440e4788, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x84bd7bfd, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x1b06d571, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x5ef9fec4, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x22d8fe39, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x99aeeb3b, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x13532244, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x2be6766b, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0xefe7e2df, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0xbfefff6d, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x83bf0278, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0xaf113f99, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x9d07f764, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x7fd62962, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x1d073a89, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x7846a318, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0xe284c527, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x9d61e50f, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x3656c8c1, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x5fc3c11, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0xc472fe2, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0xa284510b, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x4dd2dc56, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0xb1ca77b1, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x687652ce, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x42bf8a85, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x93e220bd, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x2c3731d9, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0xfdbc8a50, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0xa0973d5e, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x24b17070, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x60ec506, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x34a67b97, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x23c9f95c, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x497facc3, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0xf9e6aa4b, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x61012683, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0xc0a3098d, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0xd205520e, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0xbfd21232, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x7f229f94, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x92a27487, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x83839c4, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0xa89cb99e, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x7f7497e5, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x3aabbbaa, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0xc734385a, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x63ab0442, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0xaf2208a7, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x787f0bb, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0xF9DCBF2D, 9999, 1);
			GIVE_DELAYED_WEAPON_TO_PED(GET_PLAYER_PED(i), 0x6D544C99, 9999, 1);
		}
	 return;
	}

	if (TakeAllWeapons){
		for (int i = 1; i < 31; i++)
		{
			REMOVE_ALL_PED_WEAPONS(GET_PLAYER_PED(i), 1);
		}
		return;
	}

	if (ExplodeAll){
		for (int i = 1; i < 31; i++)
		{
			Vector3 coords = GET_ENTITY_COORDS(GET_PLAYER_PED(selectedPlayer), true);
			ADD_EXPLOSION(coords.x, coords.y, coords.z, 26, 4.0f, 1, 0, 3.0f);
		}
	}



}

void Teleport()

{
	bool TeleportToWaypoint = 0;

	AddTitle("Teleport");
	AddOption("Waypoint", TeleportToWaypoint);
	AddTele("AirPort", -1100.732f, -2893.145f, 13.9460f);
	AddOption("Interiors", null, nullFunc, SUB::INSIDEBUILDINGS);

	if (TeleportToWaypoint){
		TeleportToMarker();
		return;
	}


}

void InsideBuildings()

{


	AddTitle("Interiors");
	AddTele("Eclipse Towers", -780.507f, 337.128f, 207.621f);
	AddTele("10 Car Garage", 228.412f, -1003.383f, -99.000f);
	AddTele("10 Car Garage Room", 223.423f, -966.856f, -99.000f);
	AddTele("Character Selection", 410.861f, -999.108f, -99.204f);
	AddTele("GTA Online Winner Screen Garage", 405.540f, -975.128f, -99.004f);
	AddTele("FIB", 136.348f, -761.103f, 242.152f);
	AddTele("IAA", 119.477f, -623.069f, 206.047f);
	AddTele("Lester's House", 1274.545f, -1712.631f, 54.771f);
	if (BetaFeatures) AddTele("Cut High Life Garage", 241.30f, -988.61f, -99.00f);
	AddTele("Warehouse (Small)", 1101.36, -3099.77, -39.00);
	AddTele("Warehouse (Medium)", 1071.68, -3102.89, -39.00);
	AddTele("Warehouse (Big)", 1024.03, -3101.19, -39.00);



}
void Misc()

{
	bool sample_gta2cam = 0, superman_mode = 0, BlackoutON = 0, blackoutOFF = 0, MapP = 0, MapM = 0, SnowON = 0, SnowOFF = 0, AL2On = 0, AL2Off = 0;

	AddTitle("Misc");
	AddToggle("GTA 2 Cam", loop_gta2cam, sample_gta2cam, sample_gta2cam);
	AddToggle("Blackout", blackout, BlackoutON, blackoutOFF);
	AddToggle("Draw fps", draw_fps);
	//AddToggle("Snow", SnowCheck, SnowON, SnowOFF);
	AddText("Map", MapType, 0, null, MapP, MapM);
	AddToggle("Enable mp vehicles", AllowLowrider2, AL2On, AL2Off);
	if (BetaFeatures) AddOption("Test Menu", null, nullFunc, SUB::BETA);

	
	
	

	if (sample_gta2cam){
		if (loop_gta2cam)
		{
			if (DOES_CAM_EXIST(cam_gta2)) SET_CAM_ACTIVE(cam_gta2, 1);
			else
			{
				cam_gta2 = CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", 1);
				ATTACH_CAM_TO_ENTITY(cam_gta2, PLAYER_PED_ID(), 0.0f, 0.0f, 8.5f, 1);
				Vector3 Pos = GET_ENTITY_COORDS(PLAYER_PED_ID(), 1);
				POINT_CAM_AT_COORD(cam_gta2, Pos.x, Pos.y, -1000000);
				SET_CAM_ACTIVE(cam_gta2, 1);
			}
			RENDER_SCRIPT_CAMS(1, 0, 3000, 1, 0);
		}
		else if (DOES_CAM_EXIST(cam_gta2))
		{
			SET_CAM_ACTIVE(cam_gta2, 0);
			DESTROY_CAM(cam_gta2, 0);
			RENDER_SCRIPT_CAMS(0, 0, 3000, 1, 0);
		}
		return;
	}

	/*if (superman_mode){
		GIVE_DELAYED_WEAPON_TO_PED(PLAYER_PED_ID(), 0xFBAB5776, 1, 1);
		APPLY_FORCE_TO_ENTITY(PLAYER_PED_ID(), true, 0, 0, 40, 0, 0, 0, true, true, true, true, false, true);
		return;
	}*/

	if (BlackoutON) _SET_BLACKOUT(true);
	if (blackoutOFF) _SET_BLACKOUT(false);

	if (MapP){
		if (MapType == "SP"){ _LOAD_MP_DLC_MAPS(); _ENABLE_MP_DLC_MAPS(true); MapType = "MP"; }
		else if (MapType == "MP"){ _UNLOAD_MP_DLC_MAPS(); _ENABLE_MP_DLC_MAPS(false); MapType = "SP"; }
	}

	if (MapM){
		if (MapType == "SP"){ _LOAD_MP_DLC_MAPS(); _ENABLE_MP_DLC_MAPS(true); MapType = "MP"; }
		else if (MapType == "MP"){ _UNLOAD_MP_DLC_MAPS(); _ENABLE_MP_DLC_MAPS(false); MapType = "SP"; }
	}
	if (SnowON){
		EnableSnow(true);
	}
	if (SnowOFF){
		EnableSnow(false);
	}

	if (AL2On)
	{
		*getGlobalPtr(0x272A34) = 1;
	}
	if (AL2Off)
	{
		*getGlobalPtr(0x272A34) = 0;
	}


	

}

int startBlipI = 0;
void Beta()
{
	bool sample_gta2cam = 0, superman_mode = 0, loop_super_man = 0, load_north_yankton = 0, _cash_drop = 0, snow = 0, explode = 0, ped_can_be_targetted = 0, radar_phone_test = 0, test_2 = 0, text_test = 0, load_freemodeysc = 0, KeyBoard_test = 0, get_veh_contol = 0, DeleteVehTest = 0, Save = 0, load = 0, CreateMissionTrain = 0, MissionTrainSpeed = 0, TeleIntoMissionTrain = 0, ExitTrain = 0, get_model = 0, TrackNearestVehicle = 0, FreeCamOFF = 0, textureres = 0, notificationTest = 0, AutoMax = 0, HashTest = 0, DCTest = 0, LoadCustomScript = 0, startFire = 0, DestroyAllCams = 0, DelAllBlips = 0, SetStartBlipI = 0, CreateAndGet = 0, PrintPPID = 0, AnimColorToRed = 0, Set$GlobalVar = 0, fastMissionEnttiyLoop = 0, loadWipl = 0, wdHelper = 0;

	AddTitle("Test Menu");
	//AddOption("Load North Yankton", load_north_yankton);
	AddOption("Give 40K", _cash_drop);
	//AddOption("Christmas Snow", snow);
	AddOption("Explode", explode);
	AddOption("SET_PED_CAN_BE_TARGETTED", ped_can_be_targetted);
	AddToggle("RealisticMinimap Test", radarphone_check);
	AddToggle("Test", Test1_check);
	AddOption("Test 2", test_2);
	//AddOption("Text Test", text_test);
	AddOption("Load tuneables_processing.ysc", load_freemodeysc);
	//AddToggle("Firework Gun", fwgun_check);
	//AddOption("Keyboard Test", g_bKeyBoardDisplayed);
	AddOption("Get network control of vehicle", get_veh_contol);
	//AddToggle("Drive On Water", Drive_on_water, DriveOnWaterON, DriveOnWaterOFF);
	//AddOption("Delete Vehicle", DeleteVehTest);
	AddToggle("Brawler", brawler_check);
	AddOption("Save vehicle", Save);
	AddOption("Load vehicle", load);
	AddOption("Create Mission Train", CreateMissionTrain);
	AddToggle("Mission Train Speed Control", TrainSpeedControlCheck);
	AddOption("Change Mission Train Speed", MissionTrainSpeed);
	AddOption("Teleport Into Mission Train", TeleIntoMissionTrain);
	AddOption("Exit Train", ExitTrain);
	AddToggle("Train slow stop", TSlowStop);
	//AddToggle("Drive Trains", DriveTrainCheck);
	AddOption("Track nearest vehicle", TrackNearestVehicle);
	AddToggle("Free Cam", FreeCam, null, FreeCamOFF);
	//AddToggle("Military Taxi", MTaxi);
	AddOption("Draw texture res", textureres);
	AddOption("Notification Test", notificationTest);
	AddOption("Custom Vehicle Mod", null, nullFunc, SUB::CUSTOMVEHMOD);
	AddOption("Max Upgrades Test", AutoMax);
	AddOption("Mod labels", null, nullFunc, SUB::MODLABELS);
	AddOption("Ptfx test menu", null, nullFunc, SUB::PTFXTEST);
	AddOption("Debug console test", DCTest);
	AddKeyboard("Load custom script", LoadCustomScript);
	AddOption("Start fire", startFire);
	AddOption("Destroy all cams", DestroyAllCams);
	AddToggle("Draw coords", Draw_Coords);
	AddOption("Delete all blips", DelAllBlips);
	AddKeyboard("Set start blip index", SetStartBlipI);
	AddOption("Print player ped id", PrintPPID);
	AddOption("Color fade anim test", AnimColorToRed);
	AddKeyboard("Set money blobal var", Set$GlobalVar);
	AddToggle("Set as mission entity loop", missionEntityLoop);
	AddOption("Fast mssion entity loop", fastMissionEnttiyLoop);
	//AddOption("Hash test", HashTest);
	AddOption("Load warehouse ipl", loadWipl);
	AddKeyboard("Water damadge bike", wdHelper);

	if (load_north_yankton){
		REQUEST_IPL("prologue01");
		REQUEST_IPL("prologue01c");
		REQUEST_IPL("prologue01d");
		REQUEST_IPL("prologue01e");
		REQUEST_IPL("prologue01f");
		REQUEST_IPL("prologue01g");
		REQUEST_IPL("prologue01h");
		REQUEST_IPL("prologue01i");
		REQUEST_IPL("prologue01j");
		REQUEST_IPL("prologue01k");
		REQUEST_IPL("prologue01z");
		REQUEST_IPL("prologue02");
		REQUEST_IPL("prologue03");
		REQUEST_IPL("prologue03b");
		REQUEST_IPL("prologue04");
		REQUEST_IPL("prologue04b");
		REQUEST_IPL("prologue05");
		REQUEST_IPL("prologue05b");
		REQUEST_IPL("prologue06");
		REQUEST_IPL("prologue06b");
		REQUEST_IPL("prologuerd");
		REQUEST_IPL("prologuerdb");
		REQUEST_IPL("prologue_m2_door");
		REQUEST_IPL("prologue_LODLights");
		REQUEST_IPL("prologue_DistantLights");
		return;
	}

	if (_cash_drop){
		REQUEST_MODEL(0x113FD533);

		Vector3 pp = GET_ENTITY_COORDS(PLAYER_PED_ID(), 0);
		if (HAS_MODEL_LOADED(0x113FD533))
		{
			CREATE_AMBIENT_PICKUP(GET_HASH_KEY("PICKUP_MONEY_CASE"), pp.x, pp.y, pp.z + 1, 0, 40000, 0x113FD533, FALSE, TRUE); //WHOP YOUR WAD ON THE COUNTER
			SET_MODEL_AS_NO_LONGER_NEEDED(0x113FD533);
		}
		return;
	}

	if (explode){
		Vector3 Pos = GET_ENTITY_COORDS(PLAYER_PED_ID(), 0);
		ADD_EXPLOSION_VECTOR3(Pos.x, Pos.y, Pos.z, EXPLOSION_PLANE, 50.0f, true, true, 2.0f);
		return;
	}

	if (ped_can_be_targetted){
		set__ped_can_be_Targetted_test();
		return;
	}

	if (radar_phone_test){
		RadarPhoneTest();
		return;
	}

	if (test_2){
		PrintBottomLeft(Convert::ToString(notifications[0].NotificationSpriteAlpha));
	}

	char* PlayerNameTest = NETWORK_PLAYER_GET_NAME2(1);

	//if (text_test){
	//PrintBottomLeft(AddStrings("Welcome ", PlayerNameTest)); // Your opening message goes here.
	//return;
	//}

	if (load_freemodeysc){
		REQUEST_SCRIPT("tuneables_processing");
		while (!HAS_SCRIPT_LOADED("tuneables_processing")) WAIT(0);
		int i = START_NEW_SCRIPT("tuneables_processing", 512);
		if (i == 0) PrintDebugMessage("Script ~r~faild~s~ to load");
		else PrintDebugMessage("Script loaded");
	}

	if (get_veh_contol){
		NETWORK_REQUEST_CONTROL_OF_ENTITY(myVeh);
		return;
	}

	if (DeleteVehTest){
		Vehicle veh1 = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());
		SET_ENTITY_AS_MISSION_ENTITY(veh1, true, false);
		DELETE_VEHICLE(&veh1);
		return;
	}

	if (Save){
		SaveTest = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());
		return;
	}

	if (load){
		Vector3 SaveTestCoords = GET_ENTITY_COORDS(PLAYER_PED_ID(), true);
		SET_ENTITY_COORDS(SaveTest, SaveTestCoords.x, SaveTestCoords.y, SaveTestCoords.z, 0, 0, 0, 1);
		SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), SaveTest, -1);
		return;
	}

	if (CreateMissionTrain){
		Train1 = CREATE_MISSION_TRAIN(1, 1612.12, 3399.96, 38.66, true);
		return;
	}

	if (MissionTrainSpeed){
		SET_TRAIN_SPEED(Train1, 1000);
		return;
	}

	if (TeleIntoMissionTrain){
		Vector3 TrainPos = GET_ENTITY_COORDS(Train1, true);
		SET_ENTITY_COORDS(PLAYER_PED_ID(), TrainPos.x, TrainPos.y, TrainPos.z, 0, 0, 0, 1);
		SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), Train1, -1);
		return;
	}

	if (ExitTrain){
		Vector3 PlayerPos = GET_ENTITY_COORDS(PLAYER_PED_ID(), true);
		SET_ENTITY_COORDS(PLAYER_PED_ID(), PlayerPos.x, PlayerPos.y, PlayerPos.z, 0, 0, 0, 1);
		return;
	}

	if (TrackNearestVehicle){
		Vector3 coords = GET_ENTITY_COORDS(PLAYER_PED_ID(), true);
		Vehicle veh = GET_CLOSEST_VEHICLE(coords.x, coords.y, coords.z, 10.00, 0, 70);
		ADD_BLIP_FOR_ENTITY(veh);
		SET_ENTITY_AS_MISSION_ENTITY(veh, true, true);
	}

	if (FreeCamOFF){ SET_ENTITY_VISIBLE(PLAYER_PED_ID(), 1); FREEZE_ENTITY_POSITION(PLAYER_PED_ID(), 0); }

	if (textureres){
		static float textureres[] = { GET_TEXTURE_RESOLUTION_FLOAT("lgm_default", "adder") };
		PrintFloatBottomCentre(textureres[0], 0);
		WAIT(5000);
		PrintFloatBottomCentre(textureres[1], 0);
	}
	if (notificationTest) PrintNotification("Notification Test");

	if (AutoMax){
		SET_VEHICLE_MOD_KIT(myVeh, 0);
		for (int i = 0; i < 100; i++)
			if (true)
			{
				SET_VEHICLE_MOD(myVeh, i, 1, 1);
				TOGGLE_VEHICLE_MOD(myVeh, i, 1);
			}
	}
	if (HashTest)
	{
		PrintBottomLeft(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(0x3F75CCC1));
	}
	if (DCTest)
	{
		PrintDebugMessage(AddStrings("Test" , Convert::ToString(DebugTextsPrinted)));
	}
	if (LoadCustomScript)
	{
		char* script = GET_ONSCREEN_KEYBOARD_RESULT();
		REQUEST_SCRIPT(script);
		if (!DOES_SCRIPT_EXIST(script)){ PrintDebugMessage(AddStrings("Script ", AddStrings(script, " ~r~does not exist"))); return; }
		while (!HAS_SCRIPT_LOADED(script)) WAIT(0);
		int i = START_NEW_SCRIPT(script, 512);
		if (i == 0) PrintDebugMessage(AddStrings("Script ", AddStrings(script, " ~r~faild~s~ to load")));
		else PrintDebugMessage(AddStrings("Script ", AddStrings(script, " ~g~loaded")));
	}

	if (startFire)
	{
		Vector3 coords = GET_ENTITY_COORDS(PLAYER_PED_ID(), true);
		START_SCRIPT_FIRE(coords.x, coords.y, coords.z, 100, GET_RANDOM_INT_IN_RANGE(0, 1));
	}

	if (DestroyAllCams)
	{
		DESTROY_ALL_CAMS(1);
	}

	if (DelAllBlips)
	{
		int tmp1;
		for (int i = startBlipI; i < 20000000; i++)
		{
			tmp1 = i;
			if (DOES_BLIP_EXIST(tmp1))
			{
				REMOVE_BLIP(&tmp1);
			}
		}
	}

	if (SetStartBlipI)
	{
		startBlipI = Convert::ToInt32(GET_ONSCREEN_KEYBOARD_RESULT());
	}

	if (PrintPPID)
	{
		PrintDebugMessage(Convert::ToString(PLAYER_PED_ID()));
	}

	if (AnimColorToRed)
	{
		AnimateVehColor(myVeh, 255, 1, 1);
	}
	if (Set$GlobalVar)
	{
		*getGlobalPtr(0xCADD) = Convert::ToInt32(GET_ONSCREEN_KEYBOARD_RESULT());
	}
	if (fastMissionEnttiyLoop)
	{
		while (true)
		{
			if (!IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), true))
			{
				Vector3 myPos = GET_ENTITY_COORDS(PLAYER_PED_ID(), 0);
				Vehicle veh = CREATE_VEHICLE(0x7E8F677F, myPos.x, myPos.y, myPos.z, GET_ENTITY_HEADING(PLAYER_PED_ID()), true, 0);
				SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), veh, -1);
				SET_VEHICLE_ENGINE_ON(veh, true, true);
				SET_VEHICLE_FORWARD_SPEED(veh, tmpvar1);
			}
			else
			{
				tmpvar1 = GET_ENTITY_SPEED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()));
			}
			SET_ENTITY_AS_MISSION_ENTITY(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), true, true);
			WAIT(0);
		}
	}
	if (loadWipl)
	{
		REQUEST_IPL("ex_exec_warehouse_placement");
		REQUEST_IPL("ex_exec_warehouse_placement_interior_0_int_warehouse_m_dlc_milo_");
		REQUEST_IPL("ex_exec_warehouse_placement_interior_1_int_warehouse_s_dlc_milo_");
		REQUEST_IPL("ex_exec_warehouse_placement_interior_2_int_warehouse_l_dlc_milo_");
	}
	if (wdHelper)
	{
		Vector3 myPos = GET_ENTITY_COORDS(PLAYER_PED_ID(), 0);
		Hash model = GET_HASH_KEY(GET_ONSCREEN_KEYBOARD_RESULT());
		if (!IS_MODEL_IN_CDIMAGE(model)) { PrintBottomLeft("~r~ERROR: ~s~Invalid model"); return; }
		REQUEST_MODEL(model);
		while (!HAS_MODEL_LOADED(model)) WAIT(0);
		Vehicle veh = CREATE_VEHICLE(model, myPos.x, myPos.y, myPos.z, GET_ENTITY_HEADING(PLAYER_PED_ID()), true, 0);
		SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), veh, -1);
		WAIT(5000);
		SET_ENTITY_COORDS(PLAYER_PED_ID(), -1100.732f, -2893.145f, 13.9460f, true, true, true, 1);
		SET_ENTITY_COORDS(veh, -1100.732f, -2893.145f, 13.9460f, true, true, true, 1);
		SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), veh, -1);
	}
}
void AddPTFX(char* text, char* ptfxName)
{
	bool startPTFX = 0;
	AddOption(text, startPTFX);
	if (startPTFX)
	{
		Vector3 coords = GET_ENTITY_COORDS(PLAYER_PED_ID(), true);
		REQUEST_NAMED_PTFX_ASSET(ptfxName);
		while (!HAS_NAMED_PTFX_ASSET_LOADED(ptfxName)) WAIT(0);
		_SET_PTFX_ASSET_NEXT_CALL(ptfxName);
		START_PARTICLE_FX_NON_LOOPED_AT_COORD(ptfxName, coords.x, coords.y, coords.z, 0.0, 0.0, 0.0, 10.0, 0, 0, 0);
	}
}
void PTFXTestMenu()
{
	AddTitle("PTFX Test menu");
	AddPTFX("Test 1", "scr_carsteal4");
}
int vehModType_ = 0;
int vehModIndex_ = 0;
int vehExtraID_ = 0;
void CustomVehMod()
{
	bool ModTypeP = 0, ModTypeM = 0, ModIndexP = 0, ModIndexM = 0, Apply = 0, ExtraP = 0, ExtraM = 0, ExtraOn = 0, ExtraOff = 0, ExtraToggle = IS_VEHICLE_EXTRA_TURNED_ON(myVeh, vehExtraID_);
	AddTitle("Custom Vehicle Mod");
	AddNumber2("ModType", vehModType_, 0, Apply, ModTypeP, ModTypeM);
	AddNumber2("ModIndex", vehModIndex_, 0, Apply, ModIndexP, ModIndexM);
	/*AddNumber2("ExtraID", vehExtraID_, 0, null, ExtraP, ExtraM);
	AddToggle("Toggle", ExtraToggle, ExtraOn, ExtraOff);*/
	if (ModTypeP) vehModType_++;
	if (ModTypeM) vehModType_--;
	if (ModIndexP) vehModIndex_++;
	if (ModIndexM) vehModIndex_--;
	if (Apply){
		SET_VEHICLE_MOD_KIT(myVeh, 0);
		SET_VEHICLE_MOD(myVeh, vehModType_, vehModIndex_, 0);
	}
	if (ExtraP) vehExtraID_++;
	else if (ExtraM) vehExtraID_--;
	if (ExtraOn) SET_VEHICLE_EXTRA(myVeh, vehExtraID_, 1);
	if (ExtraOff) SET_VEHICLE_EXTRA(myVeh, vehExtraID_, 0);
}
void Recovery()

{
	bool unlock_free_chrome_rims = 0, unlock_e_tshirts = 0, unlock_lsc_mods = 0, reset_v_sell_timer = 0, purchase_all_weapons = 0, unlock_heist_vehicles = 0, two_b_snacks = 0, two_b_armor = 0, two_b_fireworks = 0, skip_tutorial = 0, clear_reports = 0;

	AddTitle("Recovery");
	AddOption("Unlock Free Chrome Rims", unlock_free_chrome_rims);
	AddOption("Unlock Exclusive T-Shirts", unlock_e_tshirts);
	AddOption("Unlock All Lsc Mods", unlock_lsc_mods);
	AddOption("Reset Vehicle Sell Timer", reset_v_sell_timer);
	AddOption("Purchase All Weapons", purchase_all_weapons);
	AddOption("Unlock Heist Vehicles", unlock_heist_vehicles);
	AddOption("2 Billion Snacks", two_b_snacks);
	AddOption("2 Billion Armor", two_b_armor);
	AddOption("2 Billion Fireworks", two_b_fireworks);
	AddOption("Skip tutorial", skip_tutorial);
	AddOption("Clear Reports", clear_reports);



	if (unlock_free_chrome_rims){
		STAT_SET_INT(Hash("MP0_AWD_WIN_CAPTURES"), 25, 1);
		STAT_SET_INT(Hash("MP0_AWD_DROPOFF_CAP_PACKAGES"), 100, 1);
		STAT_SET_INT(Hash("MP0_AWD_KILL_CARRIER_CAPTURE"), 100, 1);
		STAT_SET_INT(Hash("MP0_AWD_FINISH_HEISTS"), 50, 1);
		STAT_SET_INT(Hash("MP0_AWD_FINISH_HEIST_SETUP_JOB"), 50, 1);
		STAT_SET_INT(Hash("MP0_AWD_NIGHTVISION_KILLS"), 100, 1);
		STAT_SET_INT(Hash("MP0_AWD_WIN_LAST_TEAM_STANDINGS"), 50, 1);
		STAT_SET_INT(Hash("MP0_AWD_ONLY_PLAYER_ALIVE_LTS"), 50, 1);
		return;
	}

	if (unlock_e_tshirts){
		STAT_SET_INT(Hash("MP0_AWD_FMHORDWAVESSURVIVE"), 10, 1);
		STAT_SET_INT(Hash("MP0_AWD_FMPICKUPDLCCRATE1ST"), 1, 1);
		STAT_SET_INT(Hash("MP0_AWD_WIN_CAPTURE_DONT_DYING"), 25, 1);
		STAT_SET_INT(Hash("MP0_AWD_DO_HEIST_AS_MEMBER"), 25, 1);
		STAT_SET_INT(Hash("MP0_AWD_PICKUP_CAP_PACKAGES"), 100, 1);
		STAT_SET_BOOL(Hash("MP0_AWD_FINISH_HEIST_NO_DAMAGE"), 1, 1);
		STAT_SET_INT(Hash("MP0_AWD_WIN_GOLD_MEDAL_HEISTS"), 25, 1);
		STAT_SET_INT(Hash("MP0_AWD_KILL_TEAM_YOURSELF_LTS"), 25, 1);
		STAT_SET_INT(Hash("MP0_AWD_KILL_PSYCHOPATHS"), 100, 1);
		STAT_SET_INT(Hash("MP0_AWD_DO_HEIST_AS_THE_LEADER"), 25, 1);
		STAT_SET_BOOL(Hash("MP0_AWD_STORE_20_CAR_IN_GARAGES"), 1, 1);
		return;
	}

	if (unlock_lsc_mods){
		STAT_SET_INT(Hash("MP0_RACES_WON"), 50, 1);
		STAT_SET_INT(Hash("MP0_CHAR_FM_CARMOD_1_UNLCK"), -1, 1);
		STAT_SET_INT(Hash("MP0_CHAR_FM_CARMOD_2_UNLCK"), -1, 1);
		STAT_SET_INT(Hash("MP0_CHAR_FM_CARMOD_3_UNLCK"), -1, 1);
		STAT_SET_INT(Hash("MP0_CHAR_FM_CARMOD_4_UNLCK"), -1, 1);
		STAT_SET_INT(Hash("MP0_CHAR_FM_CARMOD_5_UNLCK"), -1, 1);
		STAT_SET_INT(Hash("MP0_CHAR_FM_CARMOD_6_UNLCK"), -1, 1);
		STAT_SET_INT(Hash("MP0_CHAR_FM_CARMOD_7_UNLCK"), -1, 1);
		STAT_SET_INT(Hash("MP0_AWD_FMRALLYWONDRIVE"), 1, 1);
		STAT_SET_INT(Hash("MP0_AWD_FMRALLYWONNAV"), 1, 1);
		STAT_SET_INT(Hash("MP0_AWD_FMWINSEARACE"), 1, 1);
		STAT_SET_INT(Hash("MP0_AWD_FMWINAIRRACE"), 1, 1);
		STAT_SET_INT(Hash("MP0_NUMBER_TURBO_STARTS_IN_RACE"), 50, 1);
		STAT_SET_INT(Hash("MP0_USJS_COMPLETED"), 50, 1);
		STAT_SET_INT(Hash("MP0_AWD_FM_RACES_FASTEST_LAP"), 50, 1);
		STAT_SET_INT(Hash("MP0_NUMBER_SLIPSTREAMS_IN_RACE"), 100, 1);
		return;
	}

	if (reset_v_sell_timer){
		STAT_SET_INT(Hash("MPPLY_VEHICLE_SELL_TIME"), 0, 1);
		return;
    }

	if (purchase_all_weapons){
		STAT_SET_INT(Hash("MP0_ADMIN_WEAPON_GV_BS_1"), -1, 1);
		STAT_SET_INT(Hash("MP0_ADMIN_WEAPON_GV_BS_2"), -1, 1);
		STAT_SET_INT(Hash("MP0_ADMIN_WEAPON_GV_BS_3"), -1, 1);
		STAT_SET_INT(Hash("MP0_BOTTLE_IN_POSSESSION"), -1, 1);
		STAT_SET_INT(Hash("MP0_CHAR_FM_WEAP_UNLOCKED"), -1, 1);
		STAT_SET_INT(Hash("MP0_CHAR_FM_WEAP_UNLOCKED2"), -1, 1);
		STAT_SET_INT(Hash("MP0_CHAR_WEAP_FM_PURCHASE"), -1, 1);
		STAT_SET_INT(Hash("MP0_CHAR_WEAP_FM_PURCHASE2"), -1, 1);
		STAT_SET_INT(Hash("MP0_CHAR_FM_WEAP_ADDON_1_UNLCK"), -1, 1);
		STAT_SET_INT(Hash("MP0_CHAR_FM_WEAP_ADDON_2_UNLCK"), -1, 1);
		STAT_SET_INT(Hash("MP0_CHAR_FM_WEAP_ADDON_3_UNLCK"), -1, 1);
		STAT_SET_INT(Hash("MP0_CHAR_FM_WEAP_ADDON_4_UNLCK"), -1, 1);
		STAT_SET_INT(Hash("MP0_CHAR_FM_WEAP_ADDON_5_UNLCK"), -1, 1);
		STAT_SET_INT(Hash("MP0_WEAP_FM_ADDON_PURCH"), -1, 1);
		STAT_SET_INT(Hash("MP0_WEAP_FM_ADDON_PURCH2"), -1, 1);
		STAT_SET_INT(Hash("MP0_WEAP_FM_ADDON_PURCH3"), -1, 1);
		STAT_SET_INT(Hash("MP0_WEAP_FM_ADDON_PURCH4"), -1, 1);
		STAT_SET_INT(Hash("MP0_WEAP_FM_ADDON_PURCH5"), -1, 1);
		PrintBottomLeft(AddStrings("All Weapons ", "Purchased"));
		return;
	}

	if (unlock_heist_vehicles){
		STAT_SET_INT(Hash("MP0_CHAR_FM_VEHICLE_1_UNLCK"), -1, 1);
		STAT_SET_INT(Hash("MP0_CHAR_FM_VEHICLE_2_UNLCK"), -1, 1);
		PrintBottomLeft(AddStrings("Heist Vehicles ", "Unlocked"));
		return;
	}

	if (two_b_snacks){
		STAT_SET_INT(Hash("MP0_NO_BOUGHT_YUM_SNACKS"), 2000000000, 1);
		STAT_SET_INT(Hash("MP0_NO_BOUGHT_HEALTH_SNACKS"), 2000000000, 1);
		STAT_SET_INT(Hash("MP0_NO_BOUGHT_EPIC_SNACKS"), 2000000000, 1);
		STAT_SET_INT(Hash("MP0_NUMBER_OF_ORANGE_BOUGHT"), 2000000000, 1);
		STAT_SET_INT(Hash("MP0_CIGARETTES_BOUGHT"), 2000000000, 1);
		PrintBottomLeft(AddStrings("2 Billion Snacks ", "Added"));
		return;
	}

	if (two_b_armor){
		STAT_SET_INT(Hash("MP0_CHAR_ARMOUR_1_COUNT"), 2000000000, 1);
		STAT_SET_INT(Hash("MP0_CHAR_ARMOUR_2_COUNT"), 2000000000, 1);
		STAT_SET_INT(Hash("MP0_CHAR_ARMOUR_3_COUNT"), 2000000000, 1);
		STAT_SET_INT(Hash("MP0_CHAR_ARMOUR_4_COUNT"), 2000000000, 1);
		STAT_SET_INT(Hash("MP0_CHAR_ARMOUR_5_COUNT"), 2000000000, 1);
		PrintBottomLeft(AddStrings("Two Billion Armor ", "Added"));
		return;
	}

	if (two_b_fireworks){
		STAT_SET_INT(Hash("MP0_FIREWORK_TYPE_1_WHITE"), 2000000000, 1);
		STAT_SET_INT(Hash("MP0_FIREWORK_TYPE_1_RED"), 2000000000, 1);
		STAT_SET_INT(Hash("MP0_FIREWORK_TYPE_1_BLUE"), 2000000000, 1);
		STAT_SET_INT(Hash("MP0_FIREWORK_TYPE_2_WHITE"), 2000000000, 1);
		STAT_SET_INT(Hash("MP0_FIREWORK_TYPE_2_RED"), 2000000000, 1);
		STAT_SET_INT(Hash("MP0_FIREWORK_TYPE_2_BLUE"), 2000000000, 1);
		STAT_SET_INT(Hash("MP0_FIREWORK_TYPE_3_WHITE"), 2000000000, 1);
		STAT_SET_INT(Hash("MP0_FIREWORK_TYPE_3_RED"), 2000000000, 1);
		STAT_SET_INT(Hash("MP0_FIREWORK_TYPE_3_BLUE"), 2000000000, 1);
		STAT_SET_INT(Hash("MP0_FIREWORK_TYPE_4_WHITE"), 2000000000, 1);
		STAT_SET_INT(Hash("MP0_FIREWORK_TYPE_4_RED"), 2000000000, 1);
		STAT_SET_INT(Hash("MP0_FIREWORK_TYPE_4_BLUE"), 2000000000, 1);
		PrintBottomLeft(AddStrings("Two Billion Fireworks ", "Added"));
		return;
	}

	if (skip_tutorial){
		STAT_SET_BOOL(Hash("MP0_NO_MORE_TUTORIALS"), 1, 1);
		PrintBottomLeft(AddStrings("Skipped ", "Tutorial"));
		return;
	}

	if (clear_reports){
		STAT_SET_INT(Hash("MPPLY_REPORT_STRENGTH"), 0, 1);
		STAT_SET_INT(Hash("MPPLY_COMMEND_STRENGTH"), 100, 1);
		STAT_SET_INT(Hash("MPPLY_FRIENDLY"), 100, 1);
		STAT_SET_INT(Hash("MPPLY_HELPFUL"), 100, 1);
		STAT_SET_INT(Hash("MPPLY_GRIEFING"), 0, 1);
		STAT_SET_INT(Hash("MPPLY_VC_ANNOYINGME"), 0, 1);
		STAT_SET_INT(Hash("MPPLY_VC_HATE"), 0, 1);
		STAT_SET_INT(Hash("MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
		STAT_SET_INT(Hash("MPPLY_OFFENSIVE_TAGPLATE"), 0, 1);
		STAT_SET_INT(Hash("MPPLY_OFFENSIVE_UGC"), 0, 1);
		STAT_SET_INT(Hash("MPPLY_BAD_CREW_NAME"), 0, 1);
		STAT_SET_INT(Hash("MPPLY_BAD_CREW_MOTTO"), 0, 1);
		STAT_SET_INT(Hash("MPPLY_BAD_CREW_STATUS"), 0, 1);
		STAT_SET_INT(Hash("MPPLY_BAD_CREW_EMBLEM"), 0, 1);
		STAT_SET_INT(Hash("MPPLY_GAME_EXPLOITS"), 0, 1);
		STAT_SET_INT(Hash("MPPLY_EXPLOITS"), 0, 1);
		STAT_SET_INT(Hash("MPPLY_ISPUNISHED"), 0, 1);
		return;
	}



}

void Vehicle1()

{
	bool fixvehicle = 0, boostvehicle = 0, superbrake = 0, superboost = 0, flip_vehicle = 0, veh_nos = 0, boostr1 = 0, superbrake_l1 = 0, carjump_x = 0, veh_launch = 0, veh_rockets = 0, remove_speed_limit = 0, VehGodmodeON = 0, VehGodmodeOFF = 0, DeleteVehicle = 0, mod_shop = 0, RainbowCarExtra = 0, DriveOnWaterON = 0, DriveOnWaterOFF = 0;

	AddTitle("Vehicle");
	AddOption("Spawn Vehicle", null, nullFunc, SUB::VEHICLESPAWNER);
	if (BetaFeatures) AddOption("Save/Load Vehicle", null, nullFunc, SUB::SAVELOADVEHICLE);
	AddProtectedSub("Mods", SUB::MODSHOP, IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), 0), mod_shop);
	AddOption("Multipliers", null, nullFunc, SUB::MULTIPLIERS);
	AddOption("Vehicle Weapons", null, nullFunc, SUB::VEHWEAPONSMENU);
	if (BetaFeatures) AddOption("Open/close doors", null, nullFunc, SUB::DOORMENU);
	AddOption("Fix", fixvehicle);
	AddToggle("Invincible", VehGodmodeCheck, VehGodmodeON, VehGodmodeOFF);
	AddToggle("Fix Loop", fixcar_check);
	AddToggle("Bind Boost", boost_check);
	AddToggle("Bind Super Brake", sbrake_check);
	AddToggle("Car Jump", carjump_check);
	AddToggle("Rainbow Color", RainbowCarCheck, RainbowCarExtra);
	AddToggle("Nitro", activenos);
	AddToggle("No Water Damage", driveunderwater_check);
	AddToggle("Drive On Water", Drive_on_water, DriveOnWaterON, DriveOnWaterOFF);
	if (BetaFeatures) AddToggle("Speedometer", speedometerCheck);
	if (BetaFeatures) AddToggle("Avoid Crashes", CrashAvoid);
	AddOption("Boost", boostvehicle);
	AddOption("Super Brake", superbrake);
	AddOption("Super Boost", superboost);
	AddOption("Flip Vehicle", flip_vehicle);
	AddOption("Launch", veh_launch);
	AddOption("Remove 540 km/h limit", remove_speed_limit);
	AddOption("Delete Vehicle", DeleteVehicle);

	if (fixvehicle){
		SET_VEHICLE_FIXED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()));
		SET_VEHICLE_DIRT_LEVEL(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0.0f);
		SET_VEHICLE_ENGINE_HEALTH(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 1000);
		SET_VEHICLE_ENGINE_ON(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), true, true);
		return;
	}

//	if (boostr1){
//		Boost__r1();
//		return;
//	}

//	if (superbrake_l1){
//		sbrake_l1();
//		return;
//	}

//	if (carjump_x){
//		car_jumper();
//		return;
//	}

	if (boostvehicle){
		SET_VEHICLE_FORWARD_SPEED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 100.0f);
        return;
    }

	if (superbrake){
		SET_VEHICLE_FORWARD_SPEED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0.0f);
		return;
	}

	if (superboost){
		SET_ENTITY_MAX_SPEED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 10000);
		SET_VEHICLE_FORWARD_SPEED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 1000.0f);
		return;
	}

	if (flip_vehicle){
		SET_VEHICLE_ON_GROUND_PROPERLY(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()));
		return;
	}

//	if (veh_nos){
//		ToggleNos();
//		return;
//	}

	if (veh_launch){
		int Handle = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());
		if (Handle != 0)
		{
			APPLY_FORCE_TO_ENTITY(Handle, true, 0, 0, 9999999999999, 0, 0, 0, true, true, true, true, false, true);
		}
	}

	//if (veh_rockets){
		//vehrockets();
		//return;
	//}

	if (remove_speed_limit){
		SET_ENTITY_MAX_SPEED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 1000);
		return;
	}

	if (VehGodmodeON){
		SET_ENTITY_INVINCIBLE(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), true);
		PrintStringBottomCentre(AddStrings("Invincible  ", "~g~ON"));
		return;
	}

	if (VehGodmodeOFF){
		SET_ENTITY_INVINCIBLE(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), false);
		PrintStringBottomCentre(AddStrings("Invincible  ", "~r~OFF"));
		return;
	}

	if (DeleteVehicle){
		Vehicle veh1 = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());
		SET_ENTITY_AS_MISSION_ENTITY(veh1, true, false);
		DELETE_VEHICLE(&veh1);
		return;
	}

	if (mod_shop){
		if (GET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())) == 3){
			PlateType = "Blue on White 1";
		}
		else if (GET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())) == 0){
			PlateType = "Blue on White 2";
		}
		else if (GET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())) == 4){
			PlateType = "Blue on White 3";
		}
		else if (GET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())) == 2){
			PlateType = "Yellow on Blue";
		}
		else if (GET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())) == 1){
			PlateType = "Yellow on Black";
		}
		else if (GET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())) == 5){
			PlateType = "North Yankton";
		}
		if (GET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())) == 1)       WindowTint = "Pure Black";
		else if (GET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())) == 2)  WindowTint = "Dark Smoke";
		else if (GET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())) == 3)  WindowTint = "Light Smoke";
		else if (GET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())) == 4)  WindowTint = "Stock";
		else if (GET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())) == 5)  WindowTint = "Limo";
		else if (GET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())) == 6)  WindowTint = "Green";
		else if (GET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())) == 0)  WindowTint = "None";
		else{ SET_VEHICLE_WINDOW_TINT(myVeh, 4); WindowTint = "Stock"; }
		SET_VEHICLE_MOD_KIT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0);
		return;
	}

	if (RainbowCarExtra){
		GET_VEHICLE_CUSTOM_PRIMARY_COLOUR(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), &rpRed, &rpGreen, &rpBlue);
		GET_VEHICLE_CUSTOM_SECONDARY_COLOUR(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), &rsRed, &rsGreen, &rsBlue);
		return;
	}

	if (DriveOnWaterON){
		Vector3 PlayerCoords = GET_ENTITY_COORDS(PLAYER_PED_ID(), true);
		RequestModel(GET_HASH_KEY("prop_ld_ferris_wheel"));
		DriveOnWaterObject = CREATE_OBJECT(GET_HASH_KEY("prop_ld_ferris_wheel"), 0, 0, 0, 1, 1, 1);
		SET_ENTITY_VISIBLE(DriveOnWaterObject, 0);
		FREEZE_ENTITY_POSITION(DriveOnWaterObject, true);
		if (IS_ENTITY_IN_WATER(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()))) {
			if (IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), true)){ SET_ENTITY_COORDS(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), PlayerCoords.x, PlayerCoords.y, WaterHeight + 1.00, true, true, true, 1); }
			else{ SET_ENTITY_COORDS(PLAYER_PED_ID(), PlayerCoords.x, PlayerCoords.y, WaterHeight + 1.00, true, true, true, 1); }
		}
	}

	if (DriveOnWaterOFF){
		SET_ENTITY_AS_MISSION_ENTITY(DriveOnWaterObject, true, true);
		DELETE_OBJECT(&DriveOnWaterObject);
	}


}
void AddDooor(char* text, int doorindex)
{
	null = 0;
	AddOption(text, null);
	if (IS_VEHICLE_DOOR_FULLY_OPEN(myVeh, doorindex))
	{
		if (OptionY < 0.6325 && OptionY > 0.1425){ DRAW_SPRITE("commonmenu", "shop_tick_icon", 0.233f + menuPos, 0.015f + OptionY, 0.036f, 0.036f, 0.0f, 255, 255, 255, 255); }
	}
	if (null)
	{
		if (IS_VEHICLE_DOOR_FULLY_OPEN(myVeh, doorindex))
		{
			PrintDebugMessage("IS_VEHICLE_DOOR_FULLY_OPEN == true");
			SET_VEHICLE_DOOR_SHUT(myVeh, doorindex, 0);
		}
		else
		{
			PrintDebugMessage("IS_VEHICLE_DOOR_FULLY_OPEN == false");
			SET_VEHICLE_DOOR_OPEN(myVeh, doorindex, 0, 0);
		}
	}
}
void DoorMenu()
{
	AddTitle("Open/close doors");
	AddDooor("Front Left Door", 0);
	AddDooor("Front Right Door", 1);
	AddDooor("Back Left Door", 2);
	AddDooor("Back Right Door", 3);
	AddDooor("Hood", 4);
	AddDooor("Trunk", 5);
	AddDooor("Back", 6);
	AddDooor("Back2", 7);
}
void AddVehWeapon(char* text, char* weapon, int check, bool atKeyDown)
{
	if (vehWeaponsCheck){
		bool SelectWeapon = 0;
		AddOption(text, SelectWeapon);
		if (SelectedVehWeapon[check])
		{
			if (OptionY < 0.6325 && OptionY > 0.1425){ DRAW_SPRITE("commonmenu", "shop_tick_icon", 0.233f + menuPos, 0.015f + OptionY, 0.036f, 0.036f, 0.0f, 255, 255, 255, 255); }
		}
		if (SelectWeapon){
			SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY(SelectedVehWeaponModel));
			VehWeaponAtKeyDown = atKeyDown;
			SelectedVehWeaponModel = weapon;
			for (int i = 0; i < sizeof(SelectedVehWeapon) / sizeof(SelectedVehWeapon[0]); i++)
				SelectedVehWeapon[i] = 0;
			SelectedVehWeapon[check] = 1;
		}
	}
	else
	{
		AddOption(text);
	}
}
void VehWeaponsMenu()
{
	bool ExtraON = 0, ExtraOFF = 0;
	AddTitle("Vehicle Weapons");
	AddToggle("Enabled", vehWeaponsCheck, ExtraON, ExtraOFF);
	AddVehWeapon("Rockets", "WEAPON_VEHICLE_ROCKET", 0, 0);
	AddVehWeapon("Combat MG", "WEAPON_COMBATMG", 1, 1);
	AddVehWeapon("Assault Shotgun", "WEAPON_ASSAULTSHOTGUN", 2, 1);
	AddVehWeapon("Hevy Sniper", "WEAPON_HEAVYSNIPER", 3, 1);
	AddVehWeapon("Grenade Launcher", "WEAPON_GRENADELAUNCHER", 4, 0);
	AddVehWeapon("Minigun", "WEAPON_MINIGUN", 5, 1);
	AddVehWeapon("Marksman Pistol", "WEAPON_MARKSMANPISTOL", 6, 1);
	AddVehWeapon("Molotov", "WEAPON_MOLOTOV", 7, 0);
	AddVehWeapon("Fireworks", "WEAPON_FIREWORK", 8, 0);
	AddVehWeapon("Snowballs", "WEAPON_SNOWBALL", 9, 0);
	if (BetaFeatures) AddVehWeapon("Flares", "WEAPON_FLAREGUN", 10, 0);

	if (ExtraON){
		for (int i = 0; i < sizeof(StoredSelectedVehWeapon) / sizeof(StoredSelectedVehWeapon[0]); i++)
			if (StoredSelectedVehWeapon[i]){ SelectedVehWeapon[i] = 1; StoredSelectedVehWeapon[i] = 0; }
	}
	if (ExtraOFF){
		for (int i = 0; i < sizeof(SelectedVehWeapon) / sizeof(SelectedVehWeapon[0]); i++)
			if (SelectedVehWeapon[i]){ StoredSelectedVehWeapon[i] = 1; SelectedVehWeapon[i] = 0; }
	}
}
void SpeedoMeterMenu()
{
	AddTitle("Speedometer");
	AddToggle("Enabled", speedometerCheck);
}
void SaveLoadVeh()
{
	AddTitle("Save/Load Vehicle");
	AddOption("Save", null, SaveVehicle);
	for (int i = 0; i < 1000; i++)
		LoadVehicle(i);
	null = 0;
	if (DebugMode) AddOption("Save editor", null, nullFunc, SUB::SAVEDVEHEDITOR);
	if (null){ tmpvar1 = 0; tmpvar2 = 0; }
}
void SavedVehEditor()
{
	bool setmodel = 0, setname = 0, color1p = 0, color1m = 0, color2p = 0, color2m = 0;
	AddTitle("Save editor");
	AddNumberSimple2("Vehicle", tmpvar1, 1000, 0);
	AddToggle("Slot used", VehSaved[tmpvar1]);
	if (VehSaved[tmpvar1])
	{
		AddKeyboard(AddStrings("Model: ", GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(SavedVehModel[tmpvar1])), setmodel);
		AddKeyboard(AddStrings("Name: ", SavedVehName[tmpvar1]), setname);
		AddNumberSimple2("Modifications", tmpvar2);
		AddNumberSimple2(Convert::ToString(tmpvar2), SavedVehMods[tmpvar1][tmpvar2]);
		AddBreak("Color");
		AddText("Color 1", ColorNames[SavedVehColor1[tmpvar1]], 0, null, color1p, color1m);
		AddText("Color 2", ColorNames[SavedVehColor2[tmpvar1]], 0, null, color2p, color2m);
		AddBreak("RGB");
		AddBreak("Primary");
		AddNumberSimple("R", SavedVehColorPR[tmpvar1], 255);
		AddNumberSimple("G", SavedVehColorPG[tmpvar1], 255);
		AddNumberSimple("B", SavedVehColorPB[tmpvar1], 255);
		AddBreak("Secondary");
		AddNumberSimple("R", SavedVehColorSR[tmpvar1], 255);
		AddNumberSimple("G", SavedVehColorSG[tmpvar1], 255);
		AddNumberSimple("B", SavedVehColorSB[tmpvar1], 255);
	}

	
	if (setmodel)
	{
		SavedVehModel[tmpvar1] = GET_HASH_KEY(GET_ONSCREEN_KEYBOARD_RESULT());
	}
	if (setname)
	{
		SavedVehName[tmpvar1] = GET_ONSCREEN_KEYBOARD_RESULT();
	}
	if (color1p)
	{
		if (SavedVehColor1[tmpvar1] == 163) SavedVehColor1[tmpvar1] = 0;
		else SavedVehColor1[tmpvar1]++;
	}
	if (color1m)
	{
		if (SavedVehColor1[tmpvar1] == 0) SavedVehColor1[tmpvar1] = 163;
		else SavedVehColor1[tmpvar1]--;
	}
	if (color2p)
	{
		if (SavedVehColor2[tmpvar1] == 163) SavedVehColor2[tmpvar1] = 0;
		else SavedVehColor2[tmpvar1]++;
	}
	if (color2m)
	{
		if (SavedVehColor2[tmpvar1] == 0) SavedVehColor2[tmpvar1] = 163;
		else SavedVehColor2[tmpvar1]--;
	}
}

void SavedVehiclesOptions()
{
	bool Load = 0, remove = 0;
	AddTitle(SavedVehName[selectedSavedVeh]);
	AddOption("Load", Load);
	AddOption("Remove", remove);
	if (Load)
	{
		Vector3 coords = GET_ENTITY_COORDS(PLAYER_PED_ID(), true);
		REQUEST_MODEL(SavedVehModel[selectedSavedVeh]);
		while (!HAS_MODEL_LOADED(SavedVehModel[selectedSavedVeh])) WAIT(0);
		Vehicle veh = CREATE_VEHICLE(SavedVehModel[selectedSavedVeh], coords.x + 3.0, coords.y, coords.z, GET_ENTITY_HEADING(PLAYER_PED_ID()), 1, 1);
		SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), myVeh, -1);
		SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, SavedVehColorPR[selectedSavedVeh], SavedVehColorPG[selectedSavedVeh], SavedVehColorPB[selectedSavedVeh]);
		SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, SavedVehColorSR[selectedSavedVeh], SavedVehColorSG[selectedSavedVeh], SavedVehColorSB[selectedSavedVeh]);
		SET_VEHICLE_COLOURS(veh, SavedVehColor1[selectedSavedVeh], SavedVehColor1[selectedSavedVeh]);
		SET_VEHICLE_MOD_KIT(myVeh, 0);
		if (DebugMode){ for (int i = 0; i < 10; i++){ PrintBottomLeft(Add3Strings(Convert::ToString(i), ": ~b~", Convert::ToString(SavedVehMods[selectedSavedVeh][i]))); WAIT(1000); } }
		for (int i = 0; i < 100; i++)
			SET_VEHICLE_MOD(veh, i, SavedVehMods[selectedSavedVeh][i], 1);
		return;
	}
	if (remove)
	{
		VehSaved[selectedSavedVeh] = 0;
		menu::SetSub_previous();
		return;
	}

}
/*void ReplaceSavedVehSlot()
{
	bool Veh1 = 0, Veh2 = 0, Veh3 = 0, Veh4 = 0, Veh5 = 0, Veh6 = 0, Veh7 = 0, Veh8 = 0;
	AddTitle("Replace Saved Vehicle");
	AddOption(SavedVeh1Name, Veh1);
	AddOption(SavedVeh2Name, Veh2);
	AddOption(SavedVeh3Name, Veh3);
	AddOption(SavedVeh4Name, Veh4);
	AddOption(SavedVeh5Name, Veh5);
	AddOption(SavedVeh6Name, Veh6);
	AddOption(SavedVeh7Name, Veh7);
	AddOption(SavedVeh8Name, Veh8);
	if (Veh1){
		SavedVeh1 = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());
		SavedVeh1Name = GET_DISPLAY_NAME_FROM_VEHICLE_MODEL((GET_ENTITY_MODEL(SavedVeh1)));
		SET_ENTITY_AS_MISSION_ENTITY(SavedVeh1, true, true);
		SET_VEHICLE_HAS_BEEN_OWNED_BY_PLAYER(SavedVeh1, true);
		menu::SetSub_previous();
		return;
	}
	if (Veh2){
		SavedVeh2 = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());
		SavedVeh2Name = GET_DISPLAY_NAME_FROM_VEHICLE_MODEL((GET_ENTITY_MODEL(SavedVeh2)));
		SET_ENTITY_AS_MISSION_ENTITY(SavedVeh2, true, true);
		SET_VEHICLE_HAS_BEEN_OWNED_BY_PLAYER(SavedVeh2, true);
		menu::SetSub_previous();
		return;
	}
	if (Veh3){
		SavedVeh3 = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());
		SavedVeh3Name = GET_DISPLAY_NAME_FROM_VEHICLE_MODEL((GET_ENTITY_MODEL(SavedVeh3)));
		SET_ENTITY_AS_MISSION_ENTITY(SavedVeh3, true, true);
		SET_VEHICLE_HAS_BEEN_OWNED_BY_PLAYER(SavedVeh3, true);
		menu::SetSub_previous();
		return;
	}
	if (Veh4){
		SavedVeh4 = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());
		SavedVeh4Name = GET_DISPLAY_NAME_FROM_VEHICLE_MODEL((GET_ENTITY_MODEL(SavedVeh4)));
		SET_ENTITY_AS_MISSION_ENTITY(SavedVeh4, true, true);
		SET_VEHICLE_HAS_BEEN_OWNED_BY_PLAYER(SavedVeh4, true);
		menu::SetSub_previous();
		return;
	}
	if (Veh5){
		SavedVeh5 = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());
		SavedVeh5Name = GET_DISPLAY_NAME_FROM_VEHICLE_MODEL((GET_ENTITY_MODEL(SavedVeh5)));
		SET_ENTITY_AS_MISSION_ENTITY(SavedVeh5, true, true);
		SET_VEHICLE_HAS_BEEN_OWNED_BY_PLAYER(SavedVeh5, true);
		menu::SetSub_previous();
		return;
	}
	if (Veh6){
		SavedVeh6 = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());
		SavedVeh6Name = GET_DISPLAY_NAME_FROM_VEHICLE_MODEL((GET_ENTITY_MODEL(SavedVeh6)));
		SET_ENTITY_AS_MISSION_ENTITY(SavedVeh6, true, true);
		SET_VEHICLE_HAS_BEEN_OWNED_BY_PLAYER(SavedVeh6, true);
		menu::SetSub_previous();
		return;
	}
	if (Veh7){
		SavedVeh7 = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());
		SavedVeh7Name = GET_DISPLAY_NAME_FROM_VEHICLE_MODEL((GET_ENTITY_MODEL(SavedVeh7)));
		SET_ENTITY_AS_MISSION_ENTITY(SavedVeh7, true, true);
		SET_VEHICLE_HAS_BEEN_OWNED_BY_PLAYER(SavedVeh7, true);
		menu::SetSub_previous();
		return;
	}
	if (Veh8){
		SavedVeh8 = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());
		SavedVeh8Name = GET_DISPLAY_NAME_FROM_VEHICLE_MODEL((GET_ENTITY_MODEL(SavedVeh8)));
		SET_ENTITY_AS_MISSION_ENTITY(SavedVeh8, true, true);
		SET_VEHICLE_HAS_BEEN_OWNED_BY_PLAYER(SavedVeh8, true);
		menu::SetSub_previous();
		return;
	}
}*/
void Multipliers()
{
	bool RpmMulti = 0, TorqueMulti = 0;
	AddTitle("Multipliers");
	AddKeyboard("Rpm Multiplier", RpmMulti);
	AddKeyboard("Torque Multiplier", TorqueMulti);

	if (RpmMulti){
		if (IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), true))
		{
			int Result;
			STRING_TO_INT(GET_ONSCREEN_KEYBOARD_RESULT(), &Result);
			_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), Result);
			PrintNotification(AddStrings("RPM Multiplier set to ", GET_ONSCREEN_KEYBOARD_RESULT()));
		}
		else PrintBottomLeft("You need a vehicle to use rpm multiplier");
	}

	if (TorqueMulti){

		STRING_TO_INT(GET_ONSCREEN_KEYBOARD_RESULT(), &TorqueMultiValue);
		TorqueMultiCheck = true;
		PrintNotification(AddStrings("Torque Multiplier set to ", GET_ONSCREEN_KEYBOARD_RESULT()));
	}
	
}
void CarColors()
{


	AddTitle("Respray");
	AddOption("Primary", null, nullFunc, SUB::PRIMARY);
	AddOption("Secondary", null, nullFunc, SUB::SECONDARY);



}


// Color menu
// Options

void AddColor(char* name, int id, ColorTypes type)
{
	int Primary, Secondary;
	bool SetColor = 0;
	AddOption(name, SetColor);
	GET_VEHICLE_COLOURS(myVeh, &Primary, &Secondary);
	if (type == ColorTypes::PRIMARY && Primary == id) DrawModSelected();
	if (type == ColorTypes::SECONDARY && Secondary == id) DrawModSelected();
	if (SetColor) 
	{
		if (type == ColorTypes::PRIMARY)
		{
			SET_VEHICLE_COLOURS(myVeh, id, Secondary);
		}
		else
		{
			SET_VEHICLE_COLOURS(myVeh, Primary, id);
		}
	}
}
void AddCustomColor(char* text, int r, int g, int b, ColorTypes type)
{
	RGBA GetColor;
	bool SetColor = 0;
	AddOption(text, SetColor);
	GET_VEHICLE_CUSTOM_PRIMARY_COLOUR(myVeh, &GetColor.R, &GetColor.G, &GetColor.B);
	if (GetColor.R == r && GetColor.G == g && GetColor.B == b) DrawModSelected();
	if (SetColor) 
	{
		if (type == ColorTypes::PRIMARY)
		{
			SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(myVeh, r, g, b);
		}
		else
		{
			SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(myVeh, r, g, b);
		}
	}
}

// Subs

void ColorCatMenu(ColorTypes type)
{
	bool customRGB = 0;

	if (type == ColorTypes::PRIMARY) AddTitle("Primary");
	else if (type == ColorTypes::SECONDARY) AddTitle("Secondary");
	if (type == ColorTypes::PRIMARY)
	{
		AddOption("Classic", null, nullFunc, SUB::PRIMARYCOLORCLASSIC);
		AddOption("Matte", null, nullFunc, SUB::PRIMARYCOLORMATTE);
		AddOption("Mettalic", null, nullFunc, SUB::PRIMARYCOLORMETALIC);
		AddOption("Preset Custom", null, nullFunc, SUB::PRESETCUSTOMCOLORS);
		AddOption("Custom RGB", customRGB, nullFunc, SUB::CUSTOMPRIMARY);
	}
	else
	{
		AddOption("Classic", null, nullFunc, SUB::SECONDARYCOLORCLASSIC);
		AddOption("Matte", null, nullFunc, SUB::SECONDARYCOLORMATTE);
		AddOption("Mettalic", null, nullFunc, SUB::SECONDARYCOLORMETALIC);
		AddOption("Preset Custom", null, nullFunc, SUB::PRESETCUSTOMSECONDARY);
		AddOption("Custom RGB", customRGB, nullFunc, SUB::CUSTOMSECONDARY);
	}


	if (customRGB)
	{
		GET_VEHICLE_CUSTOM_PRIMARY_COLOUR(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), &pRed, &pGreen, &pBlue);
		return;
	}
}
void ClassicColorMenu(ColorTypes type)
{

	char* classicColors [143][2] = { { "0", "Black" },{ "1", "Graphite" },{ "2", "Black Steel" },{ "3", "Dark Steel" },{ "4", "Silver" },{ "5", "Bluish Silver" },{ "6", "Rolled Steel" },
	{ "7", "Shadow Silver" },{ "8", "Stone Silver" },{ "9", "Midnight Silver" },{ "10", "Cast Iron Silver" },{ "11", "Anthracite Black" },{ "14", "Light Gray" },{ "15", "Util Black" },
	{ "16", "Util Black Poly" },{ "17", "Util Dark Silver" },{ "18", "Util Silver" },{ "19", "Util Gun Metal" },{ "20", "Util Shadow Silver" },{ "21", "Worn Black" },{ "22", "Worn Graphite" },
	{ "23", "Worn Silver Grey" },{ "24", "Worn Silver" },{ "25", "Worn Blue Silver" },{ "26", "Worn Shadow Silver" },{ "27", "Red" },{ "28", "Torino Red" },{ "29", "Formula Red" },{ "30", "Blaze Red" },
	{ "31", "Grace Red" },{ "32", "Garnet Red" },{ "33", "Sunset Red" },{ "34", "Cabernet Red" },{ "35", "Candy Red" },{ "36", "Sunrise Orange" },{ "37", "Gold" },{ "38", "Orange" },{ "39", "Red" },
	{ "40", "Dark Red" },{ "42", "Yellow" },{ "43", "Util Red" },{ "44", "Util Bright Red" },{ "45", "Util Garnet Red" },{ "46", "Worn Red" },{ "47", "Worn Golden Red" },{ "48", "Worn Dark Red" },
	{ "49", "Dark Green" },{ "51", "Sea Green" },{ "52", "Olive Green" },{ "53", "Bright Green" },{ "56", "Dark Green" },{ "57", "Worn Green" },{ "58", "Worn Sea Wash" },{ "61", "Galaxy Blue" },
	{ "62", "Dark Blue" },{ "63", "Saxon Blue" },{ "64", "Blue" },{ "65", "Mariner Blue" },{ "66", "Harbor Blue" },{ "67", "Diamond Blue" },{ "68", "Surf Blue" },{ "69", "Nautical Blue" },
	{ "70", "Ultra Blue" },{ "71", "Schafter Purpler" },{ "73", "Racing Blue" },{ "74", "Light Blue" },{ "75", "Util Midnight Blue" },{ "76", "Util Blue" },{ "77", "Util Sea Foam Blue" },
	{ "78", "Util Lightning Blue" },{ "79", "Util Maui Blue Poly" },{ "80", "Util Bright Blue" },{ "81", "Slate Blue" },{ "82", "Dark Blue" },{ "83", "Blue" },{ "85", "Worn Dark Blue" },{ "86", "Worn Blue" },
	{ "87", "Baby Blue" },{ "88", "Yellow" },{ "89", "Race Yellow" },{ "90", "Bronze" },{ "91", "Dew Yellow" },{ "94", "Feltzer Brown" },{ "95", "Creek Brown" },{ "96", "Chocolate Brown" },
	{ "97", "Maple Brown" },{ "98", "Saddle Brown" },{ "99", "Straw Brown" },{ "100", "Moss Brown" },{ "101", "Bison Brown" },{ "102", "Woodbeech Brown" },{ "103", "Beechwood Brown" },
	{ "104", "Straw Brown" },{ "105", "Sandy Brown" },{ "106", "Bleached Brown" },{ "107", "Cream" },{ "108", "Util Brown" },{ "109", "Util Medium Brown" },{ "110", "Util Light Brown" },{ "111", "Ice White" },
	{ "112", "Frost White" },{ "113", "Worn Honey Beige" },{ "114", "Worn Brown" },{ "115", "Dark Brown" },{ "116", "Worn Straw Beige" },{ "117", "Brushed Steel" },{ "118", "Brushed Black Steel" },
	{ "119", "Brushed Alluminum" },{ "120", "Chrome" },{ "121", "Worn Off-White" },{ "122", "Util Off-White" },{ "123", "Worn Orange" },{ "124", "Worn Light Orange" },{ "125", "Pea Green" }
	,{ "126", "Worn Taxi Yellow" },{ "127", "Police Blue" },{ "128", "Green" },{ "130", "Worn Orange" },{ "131", "Ice White" },{ "132", "Worn White" },{ "133", "Worn Olive Army Green" },
	{ "134", "Pure White" },{ "135", "Hot Pink" },{ "136", "Salmon Pink" },{ "137", "Pfister Pink" },{ "138", "Bright Orange" },{ "139", "Green" },{ "140", "Flourescent Blue" },{ "141", "Midnight Blue" },
	{ "142", "Midnight Purple" },{ "143", "Wine Red" },{ "144", "Hunter Green" },{ "145", "Bright Purple" },{ "146", "Midnight Purple" },{ "147", "Carbon Black" },{ "151", "Olive Green" },
	{ "153", "Dark Earth" },{ "154", "Desert Tan" },{ "156", "DEFAULT ALLOY" },{ "157", "Epsilon Blue" },{ "158", "Pure Gold" },{ "159", "Brushed Gold" },{ "160", "Secret Gold" } };

	AddTitle("Classic");
	for (int i = 0; i < 143; i++)
	{
		AddColor(classicColors[i][1], Convert::ToInt32(classicColors[i][0]), type);
	}

}
void MatteColorMenu(ColorTypes type)
{

	char* matteColors[10][2] = { { "12", "Matte Black" },{ "13", "Matte Gray" },{ "41", "Matte Orange" },{ "55", "Matte Lime Green" },{ "84", "Matte Midnight Blue" },{ "129", "Matte Brown" },{"148", "Matte Purple" },
	{ "149", "Matte Dark Purple" },{ "152", "Matte Olive Drab" },{ "155", "Matte Foilage Green" } };

	AddTitle("Matte");
	for (int i = 0; i < 10; i++)
	{
		AddColor(matteColors[i][1], Convert::ToInt32(matteColors[i][0]), type);
	}

}
void MettalicColorMenu(ColorTypes type)
{

	char* metalicColors[8][2] = { { "50", "Metallic Racing Green" },{ "54", "Metallic Gasoline Green" },{ "59", "Metallic Midnight Blue" },{ "60", "Metallic Dark Blue" },{ "72", "Metallic Ultra Blue" },{ "92", "Metallic Lime" },
	{ "93", "Metallic Champagne" },{ "150", "Metallic Lava Red" } };

	AddTitle("Metalic");
	for (int i = 0; i < 8; i++)
	{
		AddColor(metalicColors[i][1], Convert::ToInt32(metalicColors[i][0]), type);
	}

}
void PresetCustomColorMenu(ColorTypes type)
{
	bool Random = 0;
	AddTitle("Preset Custom");
	AddCustomColor("Black", 0, 0, 0, type);
	AddCustomColor("White", 255, 255, 255, type);
	AddCustomColor("Red", 255, 0, 0, type);
	AddCustomColor("Lime Green", 0, 255, 0, type);
	AddCustomColor("Blue", 0, 0, 255, type);
	AddCustomColor("Yellow", 255, 255, 0, type);
	AddCustomColor("Cyan", 0, 255, 255, type);
	AddCustomColor("Magenta", 255, 0, 255, type);
	AddOption("Random", Random);
	if (Random)
	{
		if (type == ColorTypes::PRIMARY)
		{
			SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(myVeh, GET_RANDOM_INT_IN_RANGE(0, 255), GET_RANDOM_INT_IN_RANGE(0, 255), GET_RANDOM_INT_IN_RANGE(0, 255));
		}
		else
		{
			SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(myVeh, GET_RANDOM_INT_IN_RANGE(0, 255), GET_RANDOM_INT_IN_RANGE(0, 255), GET_RANDOM_INT_IN_RANGE(0, 255));
		}
	}
}
void CustomColorMenu(ColorTypes type)
{
	bool custom = 0, customPlusR = 0, customMinusR = 0, customPlusG = 0, customMinusG = 0, customPlusB = 0, customMinusB = 0;

	AddTitle("Custom");
	AddNumber("Red", sRed, 0, null, customPlusR, customMinusR);
	AddNumber("Green", sGreen, 0, null, customPlusG, customMinusG);
	AddNumber("Blue", sBlue, 0, null, customPlusB, customMinusB);


	if (type == ColorTypes::PRIMARY)
	{
		SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), sRed, sGreen, sBlue);
	}
	else
	{
		SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), sRed, sGreen, sBlue);
	}


	if (customPlusR) {
		if (sRed == 255) sRed = 0;
		else sRed = sRed + 1;
		return;
	}

	if (customMinusR) {
		if (sRed == 0) sRed = 255;
		else sRed = sRed - 1;
		return;
	}

	if (customPlusG) {
		if (sGreen == 255) sGreen = 0;
		else sGreen = sGreen + 1;
		return;
	}

	if (customMinusG) {
		if (sGreen == 0) sGreen = 255;
		else sGreen = sGreen - 1;
		return;
	}

	if (customPlusB) {
		if (sBlue == 255) sBlue = 0;
		else sBlue = sBlue + 1;
		return;
	}

	if (customMinusB) {
		if (sBlue == 0) sBlue = 255;
		else sBlue = sBlue - 1;
		return;
	}
}



// Vehicle mods

void AddModSub(char* text, int Sub, int ModType)
{
	if (GET_NUM_VEHICLE_MODS(myVeh, ModType) > 0) AddOption(text, null, nullFunc, Sub);
}
void AddSuperModSub(char* text, int type)
{
	bool SetSuperModName = 0;
	if (GET_NUM_VEHICLE_MODS(myVeh, type) > 0) AddOption(text, SetSuperModName, nullFunc, SUB::BENNYSMODS);
	if (SetSuperModName){ Bennysmodname = text; bennysmodType = type; }
}
bool _VehicleMods(int modIndex)
{
	return (GET_NUM_VEHICLE_MODS(myVeh, modIndex) > 0);
}
void AddInteriorSub()
{
	if (_VehicleMods(27) || _VehicleMods(28) || _VehicleMods(30) || _VehicleMods(33) || _VehicleMods(34)) AddOption("Interior", null, nullFunc, SUB::VEHINTERIOR);
}
int getModPreset(int modIndex)
{
	switch (modIndex)
	{
	case 16: return 4;
	case 12: return 2;
	case 11: return 3;
	case 15: return 3;
	case 13: return 2;
	default: return 0;
	}
}
void ModShop()

{
	Hash VehModel = GET_ENTITY_MODEL(myVeh);
	if (!IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), true)) menu::SetSub_previous();
	bool PlatePlus = 0, PlateMinus = 0, WindowPlus = 0, WindowMinus = 0, autoUpgrade = 0;

	AddTitle("Mods");
	AddOption("Armor", null, nullFunc, SUB::ARMOUR);
	AddOption("Brakes", null, nullFunc, SUB::BRAKES);
	AddModSub(GET_MOD_SLOT_NAME(myVeh, 1), SUB::FRONTB_MENU, 1);
	AddModSub(GET_MOD_SLOT_NAME(myVeh, 4), SUB::REARB_MENU, 2);
	AddOption("Engine", null, nullFunc, SUB::ENGINE);
	AddModSub(GET_MOD_SLOT_NAME(myVeh, 4), SUB::EXHAUST, 4);
	AddModSub(GET_MOD_SLOT_NAME(myVeh, 6), SUB::GRILLE, 6);
	AddModSub(GET_MOD_SLOT_NAME(myVeh, 7), SUB::HOODS, 7);
	AddOption("Horn", null, nullFunc, SUB::HORN);
	AddOption("Lights", null, nullFunc, SUB::LIGHTS);
	AddText("Plate Type", PlateType, 0, null, PlatePlus, PlateMinus);
	AddOption("Respray", null, nullFunc, SUB::CARCOLORS);
	AddModSub(GET_MOD_SLOT_NAME(myVeh, 10), SUB::ROOF, 10);
	AddModSub(GET_MOD_SLOT_NAME(myVeh, 3), SUB::SIDE_SKIRTS, 3);
	AddModSub(GET_MOD_SLOT_NAME(myVeh, 0), SUB::SPOILER, 0);
	AddOption("Suspension", null, nullFunc, SUB::SUSPENSION);
	AddOption("Transmission", null, nullFunc, SUB::TRANSMISSION);
	AddOption("Turbo", null, nullFunc, SUB::TURBO);
	AddOption("Wheels", null, nullFunc, SUB::WHEELS);
	AddText("Windows", WindowTint, 0, null, WindowPlus, WindowMinus);
	AddInteriorSub();
	AddSuperModSub("Trunk", 20);
	AddSuperModSub("Plate holders", 25);
	AddSuperModSub("Plaques", 35);
	AddSuperModSub("Hydraulics", 38);
	AddOption("Auto Upgrade", autoUpgrade);


	if (PlatePlus){
		switch (GET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())))
		{
		case  5:  PlateType = "Blue on White 1"; SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 3);  break;
		case  3:  PlateType = "Blue on White 2"; SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0);  break;
		case  0:  PlateType = "Blue on White 3"; SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 4);  break;
		case  4:  PlateType = "Yellow on Blue"; SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 2);  break;
		case  2:  PlateType = "Yellow on Black"; SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 1);  break;
		}
	}

	if (PlateMinus){
		switch (GET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())))
		{
		case  3:  PlateType = "North Yankton"; SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 5);  break;
		case  5:  PlateType = "Yellow on Black"; SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 1);  break;
		case  1:  PlateType = "Yellow on Blue"; SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 2);  break;
		case  2:  PlateType = "Blue on White 3"; SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 4);  break;
		case  4:  PlateType = "Blue on White 2"; SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0);  break;
		}
	}

	if (WindowPlus){
		switch (GET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())))
		{
		case  0:  SET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 1); WindowTint = "Pure Black";  break;
		case  1:  SET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 2); WindowTint = "Dark Smoke";  break;
		case  2:  SET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 3); WindowTint = "Light Smoke";  break;
		case  3:  SET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 4); WindowTint = "Stock";  break;
		case  4:  SET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 5); WindowTint = "Limo";  break;
		case  5:  SET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 6); WindowTint = "Green";  break;
		case  6:  SET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0); WindowTint = "None";  break;
		default:  SET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0); WindowTint = "None";  break;
		}
	}

	if (WindowMinus){
		switch (GET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())))
		{
		case  6:  SET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 5); WindowTint = "Limo";  break;
		case  5:  SET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 4); WindowTint = "Stock";  break;
		case  4:  SET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 3); WindowTint = "Light Smoke";  break;
		case  3:  SET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 2); WindowTint = "Dark Smoke";  break;
		case  2:  SET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 1); WindowTint = "Pure Black";  break;
		case  1:  SET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0); WindowTint = "None";  break;
		case  0:  SET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 6); WindowTint = "Green";  break;
		default:  SET_VEHICLE_WINDOW_TINT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0); WindowTint = "None";  break;
		}
	}

	if (autoUpgrade)
	{
		PrintDebugMessage("Auto Upgrading");
		if (DebugMode)
		{
			if (GET_NUM_VEHICLE_MODS(myVeh, 3) != 0)
			{
				PrintDebugMessage(AddStrings("Number of vehicle mods for 3 is", Convert::ToString(GET_NUM_VEHICLE_MODS(myVeh, 3))));
				SET_VEHICLE_MOD(myVeh, 3, GET_NUM_VEHICLE_MODS(myVeh, 3), 0);
			}
			else if (getModPreset(3) != 0)
			{
				PrintDebugMessage("Numer of veh mods for 3 is 0 and there is a preset for it");
				SET_VEHICLE_MOD(myVeh, 3, getModPreset(3), 0);
			}
			else
			{
				PrintDebugMessage("Numer of veh mods for 3 is 0 and there is no preset for it");
			}
			if (GET_NUM_VEHICLE_MODS(myVeh, 11) != 0)
			{
				PrintDebugMessage(AddStrings("Number of vehicle mods for 11 is", Convert::ToString(GET_NUM_VEHICLE_MODS(myVeh, 11))));
				SET_VEHICLE_MOD(myVeh, 11, GET_NUM_VEHICLE_MODS(myVeh, 11), 0);
			}
			else if (getModPreset(11) != 0)
			{
				PrintDebugMessage("Number of vehicle mods for 11 is there is a preset for it");
				SET_VEHICLE_MOD(myVeh, 11, getModPreset(11), 0);
			}
			else
			{
				PrintDebugMessage("Number of vehicle mod for 11 is 0 and there is no preset for it");
			}
		}
		SET_VEHICLE_MOD_KIT(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0);
		for (int i = 0; i < 100; i++)
		{
			if (GET_NUM_VEHICLE_MODS(myVeh, i) != 0)
			{
				SET_VEHICLE_MOD(myVeh, i, GET_NUM_VEHICLE_MODS(myVeh, i), 0);
			}
			else if (getModPreset(i) != 0)
			{
				SET_VEHICLE_MOD(myVeh, i, getModPreset(i), 0);
			}
		}
		TOGGLE_VEHICLE_MOD(myVeh, 18, 1);
		TOGGLE_VEHICLE_MOD(myVeh, 22, 1);
	}
	


}
void VehInterior()
{
	AddTitle("Interior");
	if (GET_NUM_VEHICLE_MODS(myVeh, 27) > 0) AddOption("Trim", null, nullFunc, SUB::VEHTRIM);
	AddSuperModSub("Ornaments", 28);
	AddSuperModSub("Dials", 30);
	AddSuperModSub("Steering Wheels", 33);
	AddSuperModSub("Column Shifter Leavers", 34);
	if (GET_NUM_VEHICLE_MODS(myVeh, 30) > 0) AddOption("Light Color", null, nullFunc, SUB::VEHDASHBOARDCOLOR);
}
void VehTrim()
{
	AddTitle("Trim");
	AddSuperModSub("Trim Design", 27);
	AddOption("Trim Color", null, nullFunc, SUB::VEHINTERIORCOLOR);
}
void AddInteriorColor(char* text, int color)
{
	int GetColor;
	_GET_VEHICLE_INTERIOR_COLOUR(myVeh, &GetColor);
	bool SetColor = 0;
	AddOption(text, SetColor);
	if (GetColor == color && OptionY > 0.01) DRAW_SPRITE("commonmenu", "shop_garage_icon_b", 0.233f + menuPos, 0.015f + OptionY, 0.036f, 0.036f, 0.0f, 255, 255, 255, 255);
	if (SetColor) _SET_VEHICLE_INTERIOR_COLOUR(myVeh, color);
}
void VehInteriorColor()
{
	AddTitle("Trim Color");
	for (int i = 0; i < 161; i++)
		AddInteriorColor(ColorNames[i], i);
}
void AddDashBoardColor(char* text, int color)
{
	int GetColor;
	_GET_VEHICLE_DASHBOARD_COLOUR(myVeh, &GetColor);
	bool SetColor = 0;
	AddOption(text, SetColor);
	if (GetColor == color && OptionY > 0.01) DRAW_SPRITE("commonmenu", "shop_garage_icon_b", 0.233f + menuPos, 0.015f + OptionY, 0.036f, 0.036f, 0.0f, 255, 255, 255, 255);
	if (SetColor) _SET_VEHICLE_DASHBOARD_COLOUR(myVeh, color);
}
void VehDashBoardColor()
{
	AddTitle("Light color");
	for (int i = 0; i < 161; i++)
		AddDashBoardColor(ColorNames[i], i);
}
void AddSuperMod(int type, int index)
{
	bool InstallMod = 0;
	AddOption(_GET_LABEL_TEXT(GET_MOD_TEXT_LABEL(myVeh, type, index)), InstallMod);
	if (InstallMod)
	{
		SET_VEHICLE_MOD_KIT(myVeh, 0);
		SET_VEHICLE_MOD(myVeh, type, index, 1);
	}
}
void ModLabels()
{
	AddTitle("Mod Labels");
	for (int i = 0; i < 100; i++)
		if (GET_NUM_VEHICLE_MODS(myVeh, i) > 0) AddSuperModSub(_GET_LABEL_TEXT(GET_MOD_TEXT_LABEL(myVeh, i, 0)), i);
}
void Bennys()
{
	AddTitle("Benny's (BETA)");
	AddSuperModSub("Steering Wheel", 33);
	AddSuperModSub("Trim Design", 27);
	AddSuperModSub("Dial Design", 30);
	AddSuperModSub("Plate holders", 25);
	AddSuperModSub("Shifter Leavers", 34);
	AddSuperModSub("Unknown1", 37);
	AddSuperModSub("Plaques", 35);
	AddSuperModSub("Ornaments", 28);
	AddSuperModSub("Unknown2", 40);
	AddSuperModSub("Unknown3", 42);
	AddSuperModSub("Unknown4", 44);
	AddSuperModSub("Unknown5", 46);
	AddSuperModSub("Unknown6", 47);
	AddSuperModSub("Unknown7", 58);
	AddSuperModSub("Unknown8", 57);
	AddSuperModSub("Unknown9", 50);
	AddSuperModSub("Unknown10", 53);
	AddSuperModSub("Unknown11", 55);
	AddSuperModSub("Unknown12", 56);
	AddSuperModSub("Unknown13", 60);

}
void BennysMods()
{
	int numvehmods = GET_NUM_VEHICLE_MODS(myVeh, bennysmodType);
	AddTitle(Bennysmodname);
	AddStockVehMod("Stock", bennysmodType);
	for (int i = 0; i < numvehmods; i++)
		AddVehMod("", bennysmodType, i);
	
}
void Grille()
{
	bool stock_grille = 0;

	AddTitle("Grille");
	AddStockVehMod("Stock Grille", 6);
	AddVehMod("Grille 1", 6, 0);
	AddVehMod("Grille 2", 6, 1);
	AddVehMod("Grille 3", 6, 2);

	if (stock_grille){
		REMOVE_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 6);
		return;
	}
}

void Roof()
{
	bool stock_roof = 0;

	AddTitle("Roof");
	AddStockVehMod("Stock roof", 10);
	AddVehMod("Roof 1", 10, 0);
	AddVehMod("Roof 2", 10, 1);
	AddVehMod("Roof 3", 10, 2);

	if (stock_roof){
		REMOVE_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 6);
		return;
	}
}

void Engine()

{
	bool stock_engine = 0, super_engine = 0;

	AddTitle("Engine");
	AddStockVehMod("Stock", 11);
	AddVehMod("Level 1", 11, 0);
	AddVehMod("Level 2", 11, 1);
	AddVehMod("Level 3", 11, 2);
	AddVehMod("Level 4", 11, 3);
	//AddOption("Super Engine", super_engine);

	if (stock_engine){
		REMOVE_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 11);
		return;
	}

	if (super_engine){
		_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 500);
		return;
	}



}

void Transmission()

{
	bool stock_trans = 0;

	AddTitle("Transmission");
	AddStockVehMod("Stock Transmission", 13);
	AddVehMod("Street Transmission", 13, 0);
	AddVehMod("Sport Transmission", 13, 1);
	AddVehMod("Race Transmission", 13, 2);

	if (stock_trans){
		REMOVE_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 13);
		return;
	}


}

void Brakes()

{
	bool stock_brakes = 0;

	AddTitle("Brakes");
	AddStockVehMod("Stock Brakes", 12);
	AddVehMod("Street Brakes", 12, 0);
	AddVehMod("Sport Brakes", 12, 1);
	AddVehMod("Race Brakes", 12, 2);

	if (stock_brakes){
		REMOVE_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 12);
		return;
	}



}

void Suspension()

{
	bool stock_susp = 0;

	AddTitle("Suspension");
	AddStockVehMod("Stock Suspension", 15);
	AddVehMod("Lowered Suspension", 15, 0);
	AddVehMod("Street Suspension", 15, 1);
	AddVehMod("Sports Suspension", 15, 2);
	AddVehMod("Competition Suspension", 15, 3);

	if (stock_susp){
		REMOVE_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 15);
		return;
	}



}

void Exhaust()

{
	bool stock_ex = 0;

	AddTitle("Exhaust");
	AddStockVehMod("Stock Exhaust", 4);
	AddVehMod("Exhaust 1", 4, 0);
	AddVehMod("Exhaust 2", 4, 1);
	AddVehMod("Exhaust 3", 4, 2);

	if (stock_ex){
		REMOVE_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 4);
		return;
	}


}

void Turbo()

{
	bool turbo_0 = 0, turbo_1 = 0;

	AddTitle("Turbo");
	AddToggleVehMod("None", 18, false);
	AddToggleVehMod("Turbo Tuning", 18, true);

	if (turbo_0){
		TOGGLE_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 18, 0);
		return;
	}

	if (turbo_1){
		TOGGLE_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 18, 1);
		return;
	}



}
void LightsMenu()
{
	AddTitle("Lights");
	AddOption("HeadLights", null, nullFunc, SUB::HEADLIGHTS);
	AddOption("Neon Kits", null, nullFunc, SUB::NEON);
}
void HeadLightsMenu()
{
	AddTitle("HeadLights");
	AddToggleVehMod("Stock Lights", 22, 0);
	AddToggleVehMod("Xenon Lights", 22, 1);
}
void Neon_menu()
{
	AddTitle("Neons");
	AddOption("Layout", null, nullFunc, SUB::NEONL);
	AddOption("Color", null, nullFunc, SUB::NEONC);
}
bool NeonEnabled(int index)
{
	return _IS_VEHICLE_NEON_LIGHT_ENABLED(myVeh, index);
}
void AddNeonLayout(char* text, bool _0, bool _1, bool _2, bool _3, bool isEnabled)
{
	bool SetLayout = 0;
	AddOption(text, SetLayout);
	if (isEnabled) DrawModSelected();
	if (SetLayout)
	{
		_SET_VEHICLE_NEON_LIGHT_ENABLED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0, false);
		_SET_VEHICLE_NEON_LIGHT_ENABLED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 1, false);
		_SET_VEHICLE_NEON_LIGHT_ENABLED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 2, false);
		_SET_VEHICLE_NEON_LIGHT_ENABLED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 3, false);
		if (_0) _SET_VEHICLE_NEON_LIGHT_ENABLED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0, true);
		if (_1) _SET_VEHICLE_NEON_LIGHT_ENABLED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 1, true);
		if (_2) _SET_VEHICLE_NEON_LIGHT_ENABLED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 2, true);
		if (_3) _SET_VEHICLE_NEON_LIGHT_ENABLED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 3, true);
	}
}
void Neon_layout()
{
	bool none = 0, Left = 0, right = 0, front = 0, back = 0;

	AddTitle("Neon Layout");
	AddNeonLayout("None", 0, 0, 0, 0, !NeonEnabled(0) && !NeonEnabled(1) && !NeonEnabled(2) && !NeonEnabled(3));
	AddNeonLayout("Front", 0, 0, 1, 0, !NeonEnabled(0) && !NeonEnabled(1) && NeonEnabled(2) && !NeonEnabled(3));
	AddNeonLayout("Back", 0, 0, 0, 1, !NeonEnabled(0) && !NeonEnabled(1) && !NeonEnabled(2) && NeonEnabled(3));
	AddNeonLayout("Sides", 1, 1, 0, 0, NeonEnabled(0) && NeonEnabled(1) && !NeonEnabled(2) && !NeonEnabled(3));
	AddNeonLayout("Front and Back", 0, 0, 1, 1, !NeonEnabled(0) && !NeonEnabled(1) && NeonEnabled(2) && NeonEnabled(3));
	AddNeonLayout("Front and Sides", 1, 1, 1, 0, NeonEnabled(0) && NeonEnabled(1) && NeonEnabled(2) && !NeonEnabled(3));
	AddNeonLayout("Back and Sides", 1, 1, 0, 1, NeonEnabled(0) && NeonEnabled(1) && !NeonEnabled(2) && NeonEnabled(3));
	AddNeonLayout("Front, Back and Sides", 1, 1, 1, 1, NeonEnabled(0) && NeonEnabled(1) && NeonEnabled(2) && NeonEnabled(3));

	if (none){
		_SET_VEHICLE_NEON_LIGHT_ENABLED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0, false);
		_SET_VEHICLE_NEON_LIGHT_ENABLED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 1, false);
		_SET_VEHICLE_NEON_LIGHT_ENABLED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 2, false);
		_SET_VEHICLE_NEON_LIGHT_ENABLED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 3, false);
		return;
	}

	if (Left){
		_SET_VEHICLE_NEON_LIGHT_ENABLED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0, true);
		return;
	}

	if (right){
		_SET_VEHICLE_NEON_LIGHT_ENABLED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 1, true);
		return;
	}

	if (front){
		_SET_VEHICLE_NEON_LIGHT_ENABLED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 2, true);
		return;
	}

	if (back){
		_SET_VEHICLE_NEON_LIGHT_ENABLED(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 3, true);
		return;
	}


}

void AddCutomNeonColor(char* text, int r, int g, int b)
{
	RGBA GetColor;
	bool SetColor = 0;
	AddOption(text, SetColor);
	_GET_VEHICLE_NEON_LIGHTS_COLOUR(myVeh, &GetColor.R, &GetColor.G, &GetColor.B);
	if (GetColor.R == r && GetColor.G == g && GetColor.B == b) DrawModSelected();
	if (SetColor) _SET_VEHICLE_NEON_LIGHTS_COLOUR(myVeh, r, g, b);
}
void Neon_color()
{
	bool Random = 0, CustomRGB = 0, RainbowExtra = 0;

	AddTitle("Neon Color");
	AddToggle("Rainbow", RainbowNeonCheck, RainbowExtra);
	if (!RainbowNeonCheck){
		AddOption("Custom RGB", CustomRGB, nullFunc, SUB::NEOCUSTOMRGB);
		AddCutomNeonColor("Black", 0, 0, 0);
		AddCutomNeonColor("White", 255, 255, 255);
		AddCutomNeonColor("Red", 255, 0, 0);
		AddCutomNeonColor("Lime Green", 0, 255, 0);
		AddCutomNeonColor("Blue", 0, 0, 255);
		AddCutomNeonColor("Yellow", 255, 255, 0);
		AddCutomNeonColor("Cyan", 0, 255, 255);
		AddCutomNeonColor("Magenta", 255, 0, 255);
		AddOption("Random", Random);
	}
	if (Random) _SET_VEHICLE_NEON_LIGHTS_COLOUR(myVeh, GET_RANDOM_INT_IN_RANGE(0, 255), GET_RANDOM_INT_IN_RANGE(0, 255), GET_RANDOM_INT_IN_RANGE(0, 255));
	if (CustomRGB) _GET_VEHICLE_NEON_LIGHTS_COLOUR(myVeh, &NeonColor.R, &NeonColor.B, &NeonColor.G);
	if (RainbowExtra) _GET_VEHICLE_NEON_LIGHTS_COLOUR(myVeh, &NeonColor.R, &NeonColor.G, &NeonColor.B);
}
void NeonColorCustomRGB()
{
	bool RP = 0, RM = 0, GP = 0, GM = 0, BP = 0, BM = 0;
	AddTitle("Custom RGB");
	AddNumber("Red", NeonColor.R, 0, null, RP, RM);
	AddNumber("Green", NeonColor.G, 0, null, GP, GM);
	AddNumber("Blue", NeonColor.B, 0, null, BP, BM);
	if (RP) NeonColor.R++;
	if (RM) NeonColor.R--;
	if (GP) NeonColor.G++;
	if (GM) NeonColor.G--;
	if (BP) NeonColor.B++;
	if (BM) NeonColor.B--;
	_SET_VEHICLE_NEON_LIGHTS_COLOUR(myVeh, NeonColor.R, NeonColor.G, NeonColor.B);
}
void FrontB_Menu()

{
	bool fb_stock = 0;

	AddTitle("Front Bumper Upgrades");
	AddStockVehMod("Stock Front Bumper", 1);
	AddVehMod("Front Bumper 1", 1, 0);
	AddVehMod("Front Bumper 2", 1, 1);
	AddVehMod("Front Bumper 3", 1, 2);

	if (fb_stock){
		REMOVE_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 1);
		return;
	}



}

void RearB_Menu()

{
	bool rb_stock = 0;

	AddTitle("Rear Bumper Upgrades");
	AddStockVehMod("Stock Rear Bumper", 2);
	AddVehMod("Rear Bumper 1", 2, 0);
	AddVehMod("Rear Bumper 2", 2, 1);
	AddVehMod("Rear Bumper 3", 2, 2);

	if (rb_stock){
		REMOVE_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 2);
		return;
	}



}

void Side_skirts()

{
	bool sk_stock = 0;

	AddTitle("Side Skirts Upgrades");
	AddStockVehMod("Stock Side Skirts", 3);
	AddVehMod("Side Skirts 1", 3, 0);
	AddVehMod("Side Skirts 2", 3, 1);
	AddVehMod("Side Skirts 3", 3, 2);

	if (sk_stock){
		REMOVE_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 3);
		return;
	}



}

void Hoods()

{
	bool hood_stock = 0;

	AddTitle("Hood Upgrades");
	AddStockVehMod("Stock Hood", 7);
	AddVehMod("Hood Upgrade 1", 7, 0);
	AddVehMod("Hood Upgrade 2", 7, 1);
	AddVehMod("Hood Upgrade 3", 7, 2);
	AddVehMod("Hood Upgrade 4", 7, 3);
	AddVehMod("Hood Upgrade 5", 7, 4);

	if (hood_stock){
		REMOVE_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 7);
		return;
	}


}

void Spoiler()

{
	bool spoiler_stock = 0;

	AddTitle("Spoiler Upgrades");
	AddStockVehMod("Stock Spoiler", 0);
	AddVehMod("Spoiler 1", 0, 0);
	AddVehMod("Spoiler 2", 0, 1);
	AddVehMod("Spoiler 3", 0, 2);

	if (spoiler_stock){
		REMOVE_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 0);
		return;
	}



}

void Armour()

{
	bool armour_none = 0;

	AddTitle("Armor Upgrades");
	AddStockVehMod("None", 16);
	AddVehMod("Armor Upgrade 20%", 16, 0);
	AddVehMod("Armor Upgrade 40%", 16, 1);
	AddVehMod("Armor Upgrade 60%", 16, 2);
	AddVehMod("Armor Upgrade 80%", 16, 3);
	AddVehMod("Armor Upgrade 100%", 16, 4);

	if (armour_none){
		REMOVE_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 16);
		return;
	}



}

void Horn()
{
	bool stock = 0;
	AddTitle("Horns");
	AddStockVehMod("Stock horn", 14);
	AddVehMod("Truck", 14, 0);
	AddVehMod("Cop", 14, 1);
	AddVehMod("Clown", 14, 2);
	AddVehMod("Musical 1", 14, 3);
	AddVehMod("Musical 2", 14, 4);
	AddVehMod("Musical 3", 14, 5);
	AddVehMod("Musical 4", 14, 6);
	AddVehMod("Musical 5", 14, 7);
	AddVehMod("Sad Trombone", 14, 8);
	AddVehMod("Classical 1", 14, 9);
	AddVehMod("Classical 2", 14, 10);
	AddVehMod("Classical 3", 14, 11);
	AddVehMod("Classical 4", 14, 12);
	AddVehMod("Classical 5", 14, 13);
	AddVehMod("Classical 6", 14, 14);
	AddVehMod("Classical 7", 14, 15);
	AddVehMod("Do", 14, 16);
	AddVehMod("Re", 14, 17);
	AddVehMod("Mi", 14, 18);
	AddVehMod("Fa", 14, 19);
	AddVehMod("Sol", 14, 20);
	AddVehMod("La", 14, 21);
	AddVehMod("Ti", 14, 22);
	AddVehMod("Do (High)", 14, 23);
	AddVehMod("Jazz 1", 14, 24);
	AddVehMod("Jazz 2", 14, 25);
	AddVehMod("Jazz 3", 14, 26);
	AddVehMod("Jazz Loop", 14, 27);
	AddVehMod("Star Spangled Banner 1", 14, 28);
	AddVehMod("Star Spangled Banner 2", 14, 29);
	AddVehMod("Star Spangled Banner 3", 14, 30);
	AddVehMod("Star Spangled Banner 4", 14, 31);
	AddVehMod("Classical Horn Loop 1", 14, 32);
	AddVehMod("Classical Horn 8", 14, 33);
	AddVehMod("Classical Horn Loop 2", 14, 34);
	AddVehMod("Horn 35", 14, 35);
	AddVehMod("Horn 36", 14, 36);
	AddVehMod("Horn 37", 14, 37);
	AddVehMod("Horn 38", 14, 38);
	AddVehMod("Horn 39", 14, 39);
	AddVehMod("Horn 40", 14, 40);
	AddVehMod("Horn 41", 14, 41);
	if (stock) REMOVE_VEHICLE_MOD(GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()), 14);
}
void Wheels()
{

	bool bulletproofTires = GET_VEHICLE_TYRES_CAN_BURST(myVeh);
	bool setBulletproofTires = 0;

	AddTitle("Wheels");
	AddOption("Wheel Type", null, nullFunc, SUB::WHEELTYPE);
	AddCustomVehMod("Bulletproof tires", bulletproofTires, setBulletproofTires);
	DeleteTmpVeh();

	if (setBulletproofTires)
	{
		SET_VEHICLE_TYRES_CAN_BURST(myVeh, !bulletproofTires);
	}
}
void WheelType()
{
	CreateTmpVeh();
	bool HighEnd = 0, Lowrider = 0, Muscle = 0, Offroad = 0, sport = 0, SUV = 0, Tuner = 0;
	AddTitle("Wheel Types");
	AddWheel("Stock", 23, -1, GET_VEHICLE_WHEEL_TYPE(myVeh));
	AddOption("High end", HighEnd, nullFunc, SUB::SELECTWHEEL);
	AddOption("Lowrider", Lowrider, nullFunc, SUB::SELECTWHEEL);
	AddOption("Muscle", Muscle, nullFunc, SUB::SELECTWHEEL);
	AddOption("Offroad", Offroad, nullFunc, SUB::SELECTWHEEL);
	AddOption("Sport", sport, nullFunc, SUB::SELECTWHEEL);
	AddOption("SUV", SUV, nullFunc, SUB::SELECTWHEEL);
	AddOption("Tuner", Tuner, nullFunc, SUB::SELECTWHEEL);
	if (HighEnd) { WheelsAmount = 20; WheeltypeInt = 7; WheelTypeChar = "High end"; SET_VEHICLE_MOD_KIT(TMPVehicle, 0); SET_VEHICLE_WHEEL_TYPE(TMPVehicle, WheeltypeInt); SET_VEHICLE_MOD(TMPVehicle, 23, 0, 1); return; }
	if (Lowrider) { WheelsAmount = 15; WheeltypeInt = 2; WheelTypeChar = "Lowrider"; SET_VEHICLE_MOD_KIT(TMPVehicle, 0); SET_VEHICLE_WHEEL_TYPE(TMPVehicle, WheeltypeInt); SET_VEHICLE_MOD(TMPVehicle, 23, 0, 1); return; }
	if (Muscle) { WheelsAmount = 18; WheeltypeInt = 1; WheelTypeChar = "Muscle"; SET_VEHICLE_MOD_KIT(TMPVehicle, 0); SET_VEHICLE_WHEEL_TYPE(TMPVehicle, WheeltypeInt); SET_VEHICLE_MOD(TMPVehicle, 23, 0, 1); return; }
	if (Offroad) { WheelsAmount = 9; WheeltypeInt = 4; WheelTypeChar = "Offroad";; SET_VEHICLE_MOD_KIT(TMPVehicle, 0); SET_VEHICLE_WHEEL_TYPE(TMPVehicle, WheeltypeInt); SET_VEHICLE_MOD(TMPVehicle, 23, 0, 1); return; }
	if (sport) { WheelsAmount = 25; WheeltypeInt = 0; WheelTypeChar = "Sport"; SET_VEHICLE_MOD_KIT(TMPVehicle, 0); SET_VEHICLE_WHEEL_TYPE(TMPVehicle, WheeltypeInt); SET_VEHICLE_MOD(TMPVehicle, 23, 0, 1); return; }
	if (SUV) { WheelsAmount = 19; WheeltypeInt = 3; WheelTypeChar = "SUV"; SET_VEHICLE_MOD_KIT(TMPVehicle, 0); SET_VEHICLE_WHEEL_TYPE(TMPVehicle, WheeltypeInt); SET_VEHICLE_MOD(TMPVehicle, 23, 0, 1); return; }
	if (Tuner) { WheelsAmount = 24; WheeltypeInt = 5; WheelTypeChar = "Tuner"; SET_VEHICLE_MOD_KIT(TMPVehicle, 0); SET_VEHICLE_WHEEL_TYPE(TMPVehicle, WheeltypeInt); SET_VEHICLE_MOD(TMPVehicle, 23, 0, 1); return; }
}
void SelectWheel()
{
	AddTitle(WheelTypeChar);
	if (WheelsAmount > 1) AddWheel("Wheel 1", 23, 0, WheeltypeInt);
	if (WheelsAmount > 2) AddWheel("Wheel 2", 23, 1, WheeltypeInt);
	if (WheelsAmount > 3) AddWheel("Wheel 3", 23, 2, WheeltypeInt);
	if (WheelsAmount > 4) AddWheel("Wheel 4", 23, 3, WheeltypeInt);
	if (WheelsAmount > 5) AddWheel("Wheel 5", 23, 4, WheeltypeInt);
	if (WheelsAmount > 6) AddWheel("Wheel 6", 23, 5, WheeltypeInt);
	if (WheelsAmount > 7) AddWheel("Wheel 7", 23, 6, WheeltypeInt);
	if (WheelsAmount > 8) AddWheel("Wheel 8", 23, 7, WheeltypeInt);
	if (WheelsAmount > 9) AddWheel("Wheel 9", 23, 8, WheeltypeInt);
	if (WheelsAmount > 10) AddWheel("Wheel 10", 23, 9, WheeltypeInt);
	if (WheelsAmount > 11) AddWheel("Wheel 11", 23, 10, WheeltypeInt);
	if (WheelsAmount > 12) AddWheel("Wheel 12", 23, 11, WheeltypeInt);
	if (WheelsAmount > 13) AddWheel("Wheel 13", 23, 12, WheeltypeInt);
	if (WheelsAmount > 14) AddWheel("Wheel 14", 23, 13, WheeltypeInt);
	if (WheelsAmount > 15) AddWheel("Wheel 15", 23, 14, WheeltypeInt);
	if (WheelsAmount > 16) AddWheel("Wheel 16", 23, 15, WheeltypeInt);
	if (WheelsAmount > 17) AddWheel("Wheel 17", 23, 16, WheeltypeInt);
	if (WheelsAmount > 18) AddWheel("Wheel 18", 23, 17, WheeltypeInt);
	if (WheelsAmount > 19) AddWheel("Wheel 19", 23, 18, WheeltypeInt);
	if (WheelsAmount > 20) AddWheel("Wheel 20", 23, 19, WheeltypeInt);
	if (WheelsAmount > 21) AddWheel("Wheel 21", 23, 20, WheeltypeInt);
	if (WheelsAmount > 22) AddWheel("Wheel 22", 23, 21, WheeltypeInt);
	if (WheelsAmount > 23) AddWheel("Wheel 23", 23, 22, WheeltypeInt);
	if (WheelsAmount > 24) AddWheel("Wheel 24", 23, 23, WheeltypeInt);
	if (WheelsAmount > 25) AddWheel("Wheel 25", 23, 24, WheeltypeInt);
}
void VehicleSpawner()

{
	Vector3 myCoords = GET_ENTITY_COORDS(PLAYER_PED_ID(), 0);
	myCoords.z += 10.0f;
	Vector3 myPos = GET_ENTITY_COORDS(PLAYER_PED_ID(), 0);
	Vector3 coords = GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER_PED_ID(), 0.0, 5.0, 0.0);

	bool heli_car = 0, customInput = 0;

	AddTitle("Vehicle Spawner");
	AddOption("Spawn Settings", null, nullFunc, SUB::VSSETTINGS);
	AddKeyboard("Custom Input", customInput);
	AddOption("Super", null, nullFunc, SUB::VSSUPER);
	AddOption("Sprts", null, nullFunc, SUB::VSSPORTS);
	AddOption("Sports Classics", null, nullFunc, SUB::VSSPORTSC);
	AddOption("Off-Road", null, nullFunc, SUB::OFFROAD);
	AddOption("Muscle", null, nullFunc, SUB::MUSCLE);
	AddOption("Coupes", null, nullFunc, SUB::COUPES);
	AddOption("Compact", null, nullFunc, SUB::COMPACT);
	AddOption("SUVs and Trucks", null, nullFunc, SUB::SUVANDTRUCK);
	AddOption("Vans", null, nullFunc, SUB::VSVANS);
	AddOption("Sedans", null, nullFunc, SUB::SEDANS);
	AddOption("Emergency", null, nullFunc, SUB::VSEMERGENCY);
	AddOption("Military", null, nullFunc, SUB::VSMILITARY);
	AddOption("Service", null, nullFunc, SUB::VSSERVICE);
	//AddOption("Industrial", null, nullFunc);
	AddOption("Commercial", null, nullFunc, SUB::VSCOMMERCIAL);
	//AddOption("Utility", null, nullFunc);
	AddOption("Bicycles", null, nullFunc, SUB::VSBICYCLES);
	AddOption("Motorcycles", null, nullFunc, SUB::VSMOTORCYCLES);
	AddOption("Helicopters", null, nullFunc, SUB::VSHELICOPTERS);
	AddOption("Planes", null, nullFunc, SUB::VSPLANES);
	AddOption("Boats", null, nullFunc, SUB::VSBOATS);
	if (BetaFeatures)
	{
		//AddOption("Lowrider DLC", null, nullFunc, SUB::LOWRIDERDLC);
		AddOption("Custom", null, nullFunc, SUB::CUSTOMVEHCATEGORY);
	}
	
	//AddOption("Adder", spawn_adder);
	//AddOption("Zentorno", spawn_zentorno);
	//AddOption("Osiris", spawn_osiris);
	//AddOption("Stirling GT", spawn_StirlingGT);
	//AddOption("Marshall", spawn_marshall);
	//AddOption("Brawler", spawn_Brawler);
	//AddOption("Duke O'Death", spawn_dukes2);
	//AddOption("Hydra", spawn_hydra);
	//AddOption("Helicopter Car", heli_car);
	//AddVehicle("Adder", "Adder");
	//AddOption("PEGASUS PREMIUM", null, nullFunc, SUB::PEGASUSP);
	//AddOption("Ill Gotten Gains", null, nullFunc, SUB::IGG);

	if (heli_car){
		REQUEST_MODEL(GET_HASH_KEY("ADDER"));
		REQUEST_MODEL(GET_HASH_KEY("ANNIHILATOR"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("ADDER")) && (!HAS_MODEL_LOADED(GET_HASH_KEY("ANNIHILATOR")))) WAIT(0);
		{
			Vehicle Adder = CREATE_VEHICLE(GET_HASH_KEY("ADDER"), coords.x, coords.y, coords.z, 0.0, 1, 1);
			Vehicle Annihilator = CREATE_VEHICLE(GET_HASH_KEY("ANNIHILATOR"), coords.x, coords.y, coords.z, 0.0, 1, 1);
			ATTACH_ENTITY_TO_ENTITY(Annihilator, Adder, 0, 0, -3.9, 0, 0, 0, 0, false, false, true, false, 2, true);
		}
		return;
	}

	if (customInput){
		
			char* Result = GET_ONSCREEN_KEYBOARD_RESULT();
			if (IS_MODEL_IN_CDIMAGE(GET_HASH_KEY(Result)))
			{
				CreateVehicleHash(GET_HASH_KEY(Result));
			}
			else
			{
				PrintDebugMessage(Add3Strings("IS_MODEL_IN_CDIMAGE(GET_HASH_KEY(", Result, ")) returned false"));
				PrintBottomLeft(AddStrings("~r~Error: ~s~invalid model ~b~", Result));
			}
	}



}

void VSSettings()
{
	bool PlateTypeP = 0, PlateTypeM = 0;
	AddTitle("Spawn Settings");
	AddToggle("Spawn Inside", VSSpawnInside);
	AddToggle("Delete Last", VSDeleteLast);
	AddToggle("Spawn Upgraded", VSSpawnUpgaraded);
	AddToggle("Spawn With Custom Plate", VSSpawnWithCustomPlate);
	if (VSSpawnWithCustomPlate) AddText("Plate Type", CustomPlateType, 0, null, PlateTypeP, PlateTypeM);
	if (VSSpawnWithCustomPlate) AddText("Plate Text", CustomPlateText, 0, SetPlateText, null, null);
	
	if (PlateTypeP){
		if (VSCustomPlateType == 5){ CustomPlateType = "Blue on White 1"; VSCustomPlateType = 3; }
		else if (VSCustomPlateType == 3){ CustomPlateType = "Blue on White 2"; VSCustomPlateType = 0; }
		else if (VSCustomPlateType == 0){ CustomPlateType = "Blue on White 3"; VSCustomPlateType = 4; }
		else if (VSCustomPlateType == 4){ CustomPlateType = "Yellow on Blue"; VSCustomPlateType = 2; }
		else if (VSCustomPlateType == 2){ CustomPlateType = "Yellow on Black"; VSCustomPlateType = 1; }
		else if (VSCustomPlateType == 1){ CustomPlateType = "North Yankton"; VSCustomPlateType = 5; }
	}
	if (PlateTypeM){
		if (VSCustomPlateType == 3){ CustomPlateType = "North Yankton"; VSCustomPlateType = 5; }
		else if (VSCustomPlateType == 5){ CustomPlateType = "Yellow on Black"; VSCustomPlateType = 1; }
		else if (VSCustomPlateType == 1){ CustomPlateType = "Yellow on Blue"; VSCustomPlateType = 2; }
		else if (VSCustomPlateType == 2){ CustomPlateType = "Blue on White 3"; VSCustomPlateType = 4; }
		else if (VSCustomPlateType == 4){ CustomPlateType = "Blue on White 2"; VSCustomPlateType = 0; }
		if (VSCustomPlateType == 0){ CustomPlateType = "Blue on White 1"; VSCustomPlateType = 3; }
	}

	if (SetPlateText){
		if (!OnscreenKeyboardDisplayed)
		{
			DISPLAY_ONSCREEN_KEYBOARD(false, "", "", "", "", "", "", 30);
			OnscreenKeyboardDisplayed = true;
		}
		if (UPDATE_ONSCREEN_KEYBOARD() == 1){ CustomPlateText = GET_ONSCREEN_KEYBOARD_RESULT(); OnscreenKeyboardDisplayed = 0;  SetPlateText = 0; }
		else if (UPDATE_ONSCREEN_KEYBOARD() == 2){ PrintBottomLeft("~r~Canceled"); OnscreenKeyboardDisplayed = 0;  SetPlateText = 0; }
		else if (UPDATE_ONSCREEN_KEYBOARD() == 3){ PrintBottomLeft("~r~ERROR: Unknown Keyboard Error"); OnscreenKeyboardDisplayed = 0;  SetPlateText = 0; }
	}
}
void VSSuper()
{
	AddTitle("Super");
	AddVehicle("Truffade Adder", 0xB779A091);
	AddVehicle("Overflod Entity XF", 0xB2FE5CF9);
	AddVehicle("Grotti Cheetah", 0xB1D95DA0);
	AddVehicle("Pegassi Infernus", 0x18F25AC7);
	AddVehicle("Pegassi Vacca", 0x142E0DC3);
	AddVehicle("Vapid Bullet", 0x9AE6DDA1);
	AddVehicle("Coil Voltic", 0x9F4B77BE);
	AddVehicle("Pegassi Zentorno", 0xAC5DF515);
	AddVehicle("Grotti Turismo R", 0x185484E1);
	AddVehicle("Pegassi Osiris", 0x767164D6);
	AddVehicle("Progen T20", 0x6322B39A);
	AddVehicle("X80 Proto", 0x7E8F677F);

}
void VSSports()
{
	AddTitle("Sports");
	AddVehicle("Annis Elegy RH8", 0xDE3D9D22);
	AddVehicle("Hijak Khamelion", 0x206D1B68);
	AddVehicle("Grotti Carbonizzare", 0x7B8AB45F);
	AddVehicle("Benefactor Feltzer 1", 0x8911B9F5);
	AddVehicle("Benefactor Feltzer 2", 0xA29D6D10);
	AddVehicle("Dewbauchee Rapid GT 1", 0x8CB29A14);
	AddVehicle("Dewbauchee Rapid GT 2", 0x679450AF);
	AddVehicle("nverto Coquette 1", 0x067BC037);
	AddVehicle("Obey 9F Cabrio", 0x3D8FA25C);
	AddVehicle("Obey 9F", 0xA8E38B01);
	AddVehicle("Benefactor Surano", 0x16E478C1);
	AddVehicle("Bravado Banshee", 0xC1E908D2);
	AddVehicle("Pfister Comet", 0xC1AE4D16);
	AddVehicle("Benefactor Schwartzer", 0xD37B7976);
	AddVehicle("Schyster Fusilade", 0x1DC0BA53);
	AddVehicle("Bravado Buffalo", 0xEDD516C6);
	AddVehicle("Bravado Buffalo Sport", 0x2BEC3CBE);
	AddVehicle("Maibatsu Penumbra", 0xE9805550);
	AddVehicle("Karin Sultan", 0x39DA2754);
	AddVehicle("Karin Futo", 0x7836CE2F);
	AddVehicle("Lampadati Furore GT", 0xBF1691E0);
	AddVehicle("Dewbauchee Massacro 1", 0xF77ADE32);
	AddVehicle("Dewbauchee Massacro 2", 0xDA5819A3);
	AddVehicle("Dinka Jester 1", 0xB2A716A3);
	AddVehicle("Dinka Jester 2", 0xBE0E6126);
	AddVehicle("Enus Windsor", 0x5E4327C8);
	AddVehicle("Albany Alpha", 0x2DB8D1AA);
	AddVehicle("Karin Kuruma", 0xAE2BFE94);
	AddVehicle("Karin Kuruma(Armored)", 0x187D938D);

}

void SportsClassic()
{
	AddTitle("Sports Classic");
	AddVehicle("Inverto Coquette 2", 0x3C4E2113);
	AddVehicle("Inverto Coquette 3", 0x2EC385FE);
	AddVehicle("Truffade Z-Type", 0x2D3BD401);
	AddVehicle("Grotti Stinger GT", 0x82E499FA);
	AddVehicle("Grotti Stinger", 0x5C23AF9B);
	AddVehicle("Pegassi Monroe", 0xE62B361B);
	AddVehicle("Dewbauchee JB 700", 0x3EAB5555);
	AddVehicle("Declasse Tornado 1", 0x1BB290BC);
	AddVehicle("Declasse Tornado 2", 0x5B42A5C4);
	AddVehicle("Declasse Tornado 3", 0x690A4153);
	AddVehicle("Declasse Tornado 4", 0x86CF7CDD);
	AddVehicle("Vapid Peyote", 0x6D19CCBC);
	AddVehicle("Albany Manana", 0x81634188);
	AddVehicle("Albany Virgo", 0xE2504942);
	AddVehicle("Albany Roosevelt", 0x06FF6914);
	AddVehicle("Albany Franken Stange", 0xCE6B35A4);
	AddVehicle("Vapid Blade", 0xB820ED5E);
	AddVehicle("Benefactor Glendale", 0x047A6BC1);
	AddVehicle("Lampadati Pigalle", 0x404B6381);
	AddVehicle("Lampadati Casco", 0x3822BDFE);
	AddVehicle("Vapid Chino", 0x14D69010);
	AddVehicle("Vapid Chino Custom", 0xAED64A63);

}
void Muscle()
{
	AddTitle("Muscle");
	AddVehicle("Vapid Hotknife", 0x0239E390);
	AddVehicle("Bravado Gauntlet", 0x94B395C5);
	AddVehicle("Declasse Vigero", 0xCEC6B9B7);
	AddVehicle("Vapid Dominator", 0x04CE68AC);
	AddVehicle("Albany Buccaneer", 0xD756460C);
	AddVehicle("Albany Buccaneer Custom", 0xC397F748);
	AddVehicle("Imponte Phoenix", 0x831A21D5);
	AddVehicle("Declasse Sabre Turbo", 0x9B909C94);
	AddVehicle("Imponte Ruiner", 0xF26CEFF9);
	AddVehicle("Declasse Voodoo", 0x1F3766E3);
	AddVehicle("Declasse Voodoo Custom", 0x779B4F2D);
	AddVehicle("Cheval Picador", 0x59E0FBF3);
	AddVehicle("Rat Loader 1", 0xD83C13CE);
	AddVehicle("Rat Loader 2", 0xDCE1D9F7);
	AddVehicle("Albany Lurcher", 0x7B47A6A7);
	AddVehicle("Willard Faction", 0x81A9CDDF);
	AddVehicle("Willard Faction Custom", 0x95466BDB);
	AddVehicle("Declasse Moonbeam", 0x1F52A43F);
	AddVehicle("Declasse Moonbeam Custom", 0x710A2B9B);


}
void Sedans()
{
	AddTitle("Sedans");
	AddVehicle("Enus Super Diamond", 0x42F2ED16);
	AddVehicle("Ubermacht Oracle 1", 0x506434F6);
	AddVehicle("Ubermacht Oracle 2", 0xE18195B2);
	AddVehicle("Dundreary Stretch", 0x8B13F083);
	AddVehicle("Cheval Fugitive", 0x71CB2FFB);
	AddVehicle("Cheval Surge", 0x8F0E3594);
	AddVehicle("Benefactor Schafter", 0xB52B5113);
	AddVehicle("Karin Asterope", 0x8E9254FB);
	AddVehicle("Karin Intruder", 0x34DD8AA1);
	AddVehicle("Albany Washington", 0x69F06B57);
	AddVehicle("Vapid Stanier", 0xA7EDE74D);
	AddVehicle("Vulcan Ingot", 0xB3206692);
	AddVehicle("Albany Emperor 1", 0xD7278283);
	AddVehicle("Albany Emperor 2", 0x8FC3AADC);
	AddVehicle("Albany Emperor 3", 0xB5FCF74E);
	AddVehicle("Albany Primo", 0xBB6B404F);
	AddVehicle("Albany Primo Custom", 0x86618EDA);
	AddVehicle("Dundreary Regina", 0xFF22D208);
	AddVehicle("Chariot Romero Hearse", 0x2560B2FC);
	AddVehicle("Obey Tailgater", 0xC3DDFDCE);
	AddVehicle("Declasse Premier", 0x8FB66F9B);
	AddVehicle("Zirconium Stratum", 0x66B4FC45);
	AddVehicle("Declasse Asea 1", 0x94204D89);
	AddVehicle("Declasse Asea 2", 0x9441D8D5);

}
void Coupes()
{
	AddTitle("Coupes");
	AddVehicle("Dewbauchee Exemplar", 0xFFB15B5E);
	AddVehicle("Enus Cognoscenti Cabrio", 0x13B57D8A);
	AddVehicle("Lampadati Felon GT", 0xFAAD85EE);
	AddVehicle("Lampadati Felon", 0xE8A8BDA8);
	AddVehicle("Ubermacht Zion Cabrio", 0xBD1B39C3);
	AddVehicle("Ubermacht Zion", 0xB8E2AE18);
	AddVehicle("Ubermacht Sentinel XS", 0x50732C82);
	AddVehicle("Ubermacht Sentinel", 0x3412AE2D);
	AddVehicle("Ocelot F620", 0xDCBCBE48);
	AddVehicle("Ocelot Jackal", 0xDAC67112);

}
void Compact()
{
	AddTitle("Compact");
	AddVehicle("Karin Dilettante 1", 0xBC993509);
	AddVehicle("Karin Dilettante 2", 0x64430650);
	AddVehicle("Weeny Issi", 0xB9CB3B69);
	AddVehicle("Bollokan Prairie", 0xA988D3A2);
	AddVehicle("Dinka Blista", 0xEB70965F);
	AddVehicle("Declasse Rhapsody", 0x322CF98F);
	AddVehicle("Vulcar Warrener", 0x51D83328);
	AddVehicle("Benefactor Panto", 0xE644E480);

}

void SUVandTruck()
{
	AddTitle("SUVs and Trucks");
	AddVehicle("Gallivanter Baller 1", 0xCFCA3668);
	AddVehicle("Gallivanter Baller 2", 0x08852855);
	AddVehicle("Obey Rocoto", 0x7F5C91F1);
	AddVehicle("Albany Cavalcade 1", 0x779F23AA);
	AddVehicle("Albany Cavalcade 2", 0xD0EB2BE5);
	AddVehicle("Benefactor Dubsta 1", 0x462FE277);
	AddVehicle("Benefactor Dubsta 2", 0xE882E5F6);
	AddVehicle("Benefactor Dubsta 3", 0xB6410173);
	AddVehicle("Benefactor Serrano", 0x4FB1A214);
	AddVehicle("Dundreary Landstalker", 0x4BA4E8DC);
	AddVehicle("Fathom FQ 2", 0xBC32A33B);
	AddVehicle("Mammoth Patriot", 0xCFCFEB3B);
	AddVehicle("Emperor Habanero", 0x34B7390F);
	AddVehicle("Vapid Radius", 0x9D96B45B);
	AddVehicle("Declasse Granger", 0x9628879C);
	AddVehicle("Canis Mesa 1", 0x36848602);
	AddVehicle("Canis Mesa 2", 0xD36A4B44);
	AddVehicle("Canis Seminole", 0x48CECED3);
	AddVehicle("Canis Kalahari", 0x05852838);
	AddVehicle("Bravado Gresley", 0xA3FC0F4D);
	AddVehicle("Karin BeeJay XL", 0x32B29A4B);
	AddVehicle("Enus Huntley", 0x1D06D681);
	AddVehicle("Sadler 1", 0xDC434E51);
	AddVehicle("Sadler 2", 0x2BC345D1);
	AddVehicle("Vapid Guardian", 0x825A9F4C);
	AddVehicle("HVY Insurgent", 0x9114EADA);
	AddVehicle("HVY Insurgent(Pickup)", 0x7B7E56F0);
	AddVehicle("Karin Technical", 0x83051506);

}
void OffRoad()
{
	AddTitle("OffRoad");
	AddVehicle("Liberator", 0xCD93A7DB);
	AddVehicle("Vapid Sandking XL", 0xB9210FD0);
	AddVehicle("BF Dune Buggy", 0x9CF21E0F);
	AddVehicle("Space Docker", 0x1FD824AF);
	AddVehicle("BF Injection", 0x432AA566);
	AddVehicle("BF Bifta", 0xEB298297);
	AddVehicle("Nagasaki Blazer 1", 0x8125BCF9);
	AddVehicle("Trevors Blazer", 0xB44F0582);
	AddVehicle("Canis Mesa (Merryweather)", 0x84F42E51);
	AddVehicle("Vapid Sandking SWB", 0x3AF8C345);
	AddVehicle("Bravado Duneloader", 0x698521E3);
	AddVehicle("Canis Bodhi", 0xAA699BB6);
	AddVehicle("Declasse Rancher XL 1", 0x6210CBB0);
	AddVehicle("Declasse Rancher XL 2", 0x7341576B);
	AddVehicle("Karin Rebel 1", 0xB802DD46);
	AddVehicle("Karin Rebel 2", 0x8612B64B);
	AddVehicle("Nagasaki Blazer Lifeguard", 0xFD231729);
	AddVehicle("Coil Brawler", 0xA7CE1BC5);
	AddVehicle("Dinka Enduro", 0x6882FA73);

}
void Vans()
{
	char* VansNames[31] = { "Bravado Bison 1", "Bravado Bison 2", "Bravado Bison 3", "Bravado Paradise", "Zirconium Journey", "Vapid Minivan", "Vapid Bobcat XL", "Bravado Rumpo 1", "Bravado Rumpo 2", "Brute Pony 1", "Brute Pony 2", "Declasse Burrito 1", "Declasse Burrito 2", "Declasse Burrito 3", "Declasse Burrito 4", "Declasse Burrito 5", "Declasse Burrito 6", "Declasse Burrito 7", "Vapid Speedo 1", "Vapid Speedo 2", "Bravado Youga", "Boxville 1", "Boxville 2", "Boxville 3", "Boxville 4", "Brute Camper", "Taco Van", "BF Surfer", "BF Surfer (Rusted)", "Vapid Slamvan 1", "Vapid Slamvan 2" };
	Hash VansHashes[31] = { 0xFEFD644F, 0x7B8297C5, 0x67B3F020, 0x58B3979C, 0xF8D48E7A, 0xED7EADA4, 0x3FC5D440, 0x4543B74D, 0x961AFEF7, 0xF8DE29A8, 0x38408341, 0xAFBB2CA4, 0xC9E8FF76, 0x98171BD3, 0x353B561D, 0x437CF2A0, 0x11AA0E14, 0x97FA4F36, 0xCFB3870C, 0x2B6DC64A, 0x03E5F6B8, 0x898ECCEA, 0xF21B33BE, 0x07405E08, 0x1A79847A, 0x6FD95F68, 0x744CA80D, 0x29B0DA97, 0xB1D80E06, 0x2B7F9DE3, 0x31ADBBFC };
	AddTitle("Vans");
	for (int i = 0; i < sizeof(VansNames) / sizeof(char*); i++)
		AddVehicle(VansNames[i], VansHashes[i]);
}
void Emergency()
{
	char* EmergencyNames[18] = { "FIB", "FIB SUV", "Firetruck", "Ambulance", "Police 1", "Police 2", "Police 3", "Police 4", "Police Bike", "Police Old 1", "Police Old 2", "Police Van", "Swat Truck", "Sheriff 1", "Sheriff 2", "Prison Bus", "Park Ranger", "Life Guard SUV" };
	Hash EmergencyHashes[18] = { 0x432EA949, 0x9DC66994, 0x73920F8E, 0x45D56ADA, 0x79FBB0C5, 0x9F05F101, 0x71FA16EA, 0x8A63C7B9, 0xFDEFAEC3, 0xA46462F7, 0x95F4C618, 0x1B38E955, 0xB822A1AA, 0x9BAA707C, 0x72935408, 0x885F3671, 0x2C33B46E, 0x1BF8D381 };
	AddTitle("Emergency");
	for (int i = 0; i < sizeof(EmergencyNames) / sizeof(char*); i++)
		AddVehicle(EmergencyNames[i], EmergencyHashes[i]);
}
void Service()
{
	char* ServiceNames[6] = { "Airport Bus", "Dashhound", "Bus", "Rental Shuttle Bus", "Tour Bus", "Taxi" };
	Hash ServiceHashes[6] = { 0x4C80EB0E, 0x84718D34, 0xD577C962, 0xBE819C63, 0x73B1C3CB, 0xC703DB5F };
	AddTitle("Service");
	for (int i = 0; i < sizeof(ServiceNames) / sizeof(char*); i++)
		AddVehicle(ServiceNames[i], ServiceHashes[i]);
}
void Military()
{
	char* MilitaryNames[7] = { "Rhino Tank", "Barracks 1", "Barracks 2", "Barracks 3", "Canis Crusader", "Tanker 1", "Tanker 2" };
	Hash MilitaryHashes[7] = { 0x2EA68690, 0xCEEA3F4B, 0x4008EABB, 0x2592B5CF, 0x132D5A1A, 0xD46F4737, 0x74998082 };
	AddTitle("Military");
	for (int i = 0; i < sizeof(MilitaryNames) / sizeof(char*); i++)
		AddVehicle(MilitaryNames[i], MilitaryHashes[i]);
}
void Motorcycles()
{
	char* MotorcyclesNames[21] = { "Nagasaki Carbon RS", "Pegassi Bati 801RR", "Pegassi Bati 801", "LCC Hexer", "LCC Innovation", "Dinka Double-T", "Dinka Thrust", "Dinka Vindicator", "Pegassi Ruffian", "Shitzu Vader", "Shitzu PCJ 600", "Shitzu Hakuchou", "Dinka Akuma", "Maibatsu Sanchez (Decal)", "Maibatsu Sanchez", "Pegassi ***gio", "Western Daemon", "Western Bagger", "Principe Nemesis", "Sovereign", "Principe Lectro" };
	Hash MotorcyclesHashes[21] = { 0x00ABB0C0, 0xCADD5D2D, 0xF9300CC5, 0x11F76C14, 0xF683EACA, 0x9C669788, 0x6D6F8F43, 0xAF599F01, 0xCABD11E8, 0xF79A00F7, 0xC9CEAF06, 0x4B6C568A, 0x63ABADE7, 0x2EF89E46, 0xA960B13E, 0x0350D1AB, 0x77934CEE, 0x806B9CC3, 0xDA288376, 0x2C509634, 0x26321E67 };
	AddTitle("Motorcycles");
	for (int i = 0; i < sizeof(MotorcyclesNames) / sizeof(char*); i++)
		AddVehicle(MotorcyclesNames[i], MotorcyclesHashes[i]);
}
void Bicycles()
{
	char* BicyclesNames[7] = { "Whippet Race Bike", "Tri-Cycles Race Bike", "Scorcher", "Endurex Race Bike", "Cruiser", "BMX", "Fixter" };
	Hash BicyclesHashes[7] = { 0x4339CD69, 0xE823FB48, 0xF4E1AA15, 0xB67597EC, 0x1ABA13B5, 0x43779C54, 0xCE23D3BF };
	AddTitle("Bicycles");
	for (int i = 0; i < sizeof(BicyclesNames) / sizeof(char*); i++)
		AddVehicle(BicyclesNames[i], BicyclesHashes[i]);
}
void Commercial()
{
	char* CommercialNames[39] = { "Maibatsu Mule 1", "Maibatsu Mule 2", "Maibatsu Mule 3", "JoBuilt Phantom", "Vapid Benson", "MTL Packer", "MTL Pounder", "JoBuilt Hauler", "Brute Stockade 1", "Brute Stockade 2", "HVY Biff", "HVY Dump", "HVY Dozer", "HVY Forklift", "HVY Handler", "HVY Cutter", "Utility Truck 1", "Utility Truck 2", "Utility Truck 3", "Trashmaster 1", "Trashmaster 2", "Towtruck 1", "Towtruck 2", "TipTruck 1", "TipTruck 2", "Mixer 1", "Mixer 2", "Flatbed Truck", "Airport Ripley", "Rubble", "Vapid Scrap Truck", "Lawnmower", "Dock Tug", "Airport Tug", "Tractor 1", "Tractor 2", "Tractor 3", "Caddy 1", "Caddy 2" };
	Hash CommercialHashes[39] = { 0x35ED670B, 0xC1632BEB, 0x85A5B471, 0x809AA4CB, 0x7A61B330, 0x21EEE87D, 0x7DE35E7D, 0x5A82F9AE, 0x6827CF72, 0xF337AB36, 0x32B91AE8, 0x810369E2, 0x7074F39D, 0x58E49664, 0x1A7FCEFA, 0xC3FBA120, 0x1ED0A534, 0x34E6BF6B, 0x7F2153DF, 0x72435A19, 0xB527915C, 0xB12314E0, 0xE5A2D6C6, 0x02E19879, 0xC7824E5E, 0xD138A6BB, 0x1C534995, 0x50B0215A, 0xCD935EF9, 0x9A5B1DCC, 0x9A9FD3DF, 0x6A4BD8F6, 0xCB44B1CA, 0x5D0AAC8F, 0x61D6BA8C, 0x843B73DE, 0x562A97BD, 0x44623884, 0xDFF0594C };
	AddTitle("Commercial");
	for (int i = 0; i < sizeof(CommercialNames) / sizeof(char*); i++)
		AddVehicle(CommercialNames[i], CommercialHashes[i]);
}
void Helicopters()
{
	char* HelicoptersNames[14] = { "Annihilator", "Buzzard Attack Chopper 1", "Buzzard Attack Chopper 2", "Frogger 1", "Frogger 2", "Maverick", "Cargobob 1", "Cargobob 2", "Cargobob 3", "Police Maverick", "Swift 1", "Swift 2", "Buckingham Valkyrie", "Savage" };
	Hash HelicoptersHashes[14] = { 0x31F0B376, 0x2F03547B, 0x2C75F0DD, 0x2C634FBD, 0x742E9AC0, 0x9D0450CA, 0xFCFCB68B, 0x60A7EA10, 0x53174EEF, 0x1517D4D9, 0xEBC24DF2, 0x4019CB4C, 0xA09E15FD, 0xFB133A17 };
	AddTitle("Helicopters");
	for (int i = 0; i < sizeof(HelicoptersNames) / sizeof(char*); i++)
		AddVehicle(HelicoptersNames[i], HelicoptersHashes[i]);
}
void Planes()
{
	char* PlanesNames[19] = { "Titan", "Buckingham Luxor 1", "Buckingham Luxor 2", "Buckingham Shamal", "Buckingham Vestra", "Buckingham Miljet", "Velum 1", "Velum 2", "Mammatus", "Duster", "Mallard", "Cuban 800", "Cargo Plane", "Blimp", "P-996 Lazer", "Skylift", "Jet", "Bersa", "Mammoth Hydra" };
	Hash PlanesHashes[19] = { 0x761E2AD3, 0x250B0C5E, 0xB79F589E, 0xB79C1BF5, 0x4FF77E37, 0x09D80F93, 0x9C429B6A, 0x403820E8, 0x97E55D11, 0x39D6779E, 0x81794C70, 0xD9927FE3, 0x15F27762, 0xF7004C86, 0xB39B0AE6, 0x3E48BF23, 0x3F119114, 0x6CBD1D6D, 0x39D6E83F };
	AddTitle("Planes");
	for (int i = 0; i < sizeof(PlanesNames) / sizeof(char*); i++)
		AddVehicle(PlanesNames[i], PlanesHashes[i]);
}
void Boats()
{
	char* BoatsNames[14] = { "Dinka Marquis", "Shitzu Jetmax", "Shitzu Squalo", "Shitzu Suntrap", "Shitzu Tropic", "Speedophile Seashark 1", "Speedophile Seashark 2", "Police Predator", "Submarine", "Pegassi Speeder", "Nagasaki Dinghy 1", "Nagasaki Dinghy 2", "Nagasaki Dinghy 3", "Lampadati Toro" };
	Hash BoatsHashes[14] = { 0xC1CE1183, 0x33581161, 0x17DF5EC2, 0xEF2295C9, 0x1149422F, 0xC2974024, 0xDB4388E4, 0xE2E7D4AB, 0x2DFF622F, 0x0DC60D2B, 0x3D961290, 0x107F392C, 0x1E5E54EA, 0x3FD5AA2F };
	AddTitle("Boats");
	for (int i = 0; i < sizeof(BoatsNames) / sizeof(char*); i++)
		AddVehicle(BoatsNames[i], BoatsHashes[i]);
}
void Trailers()
{
	char* TrailersNames[27] = { "Army Tanker", "Army Trailer 1", "Army Trailer 2", "Bale Trailer", "Boat Trailer", "Cablecar", "Dock Trailer", "Freight Car 1", "Freight Car 2", "Freight Container 1", "Freight Container 2", "Freight Train Boxcar", "Grain Trailer", "Metro Train", "Mobile Home Trailer", "Rake Trailer", "Train Fuel Tank Car", "Car Carrier Trailer", "Marquis Trailer", "Super Car Carrier Trailer", "Trailer Logs", "Trailers 1", "Trailers 2", "Trailers 3", "Trailer Small", "Trailer Flat", "Tv Trailer" };
	unsigned int TrailersHashes[27] = { 0xB8081009, 0xA7FF33F5, 0x9E6B14D6, 0xE82AE656, 0x1F3D44B5, 0xC6C3242D, 0x806EFBEE, 0x3D6AAA9B, 0x0AFD22A6, 0x36DCFF98, 0x0E512E79, 0x264D9262, 0x3CC7F596, 0x33C9E158, 0x153E1B0A, 0x174CB172, 0x22EDDC30, 0x7BE032C6, 0x6A59902D, 0x7CAB34D0, 0x782A236D, 0xCBB2BE0E, 0xA1DA3C91, 0x8548036D, 0x2A72BEAB, 0xAF62F6B2, 0x967620BE };
	AddTitle("Trailers");
	for (int i = 0; i < sizeof(TrailersNames) / sizeof(char*); i++)
		AddVehicle(TrailersNames[i], TrailersHashes[i]);
}
void LowrideDLC()
{
	char* vehicles[12] = {"faction2", "faction3", "moonbeam2", "primo2", "sabregt2", "virgo2", "virgo3", "chino2", "voodoo", "buccaneer2", "tornado5", "slamvan3"};
	AddTitle("Lowrider DLC");
	for (int i = 0; i < sizeof(vehicles) / sizeof(char*); i++)
		AddVehicle(vehicles[i], GET_HASH_KEY(vehicles[i]));
}
void CustomVehCategory()
{
	AddTitle("Custom");
	AddToggle("Edit", CustomVehEditMode);
	if (CustomVehEditMode)
	{
		bool Add = 0;
		AddOption("Add", Add, nullFunc, SUB::ADDTOCUSTOMVEHICLES);
		AddOption("Delete", null, nullFunc, SUB::DELTEFROMCUSTOMVEHICLES);

		if (Add)
		{
			CustomvehicleModels[customVehiclesCount] = 0;
			CustomVehicleNames[customVehiclesCount] = "NULL";
		}
	}

	for (int i = 0; i < customVehiclesCount; i++)
	{
		AddVehicleCustomName(CustomVehicleNames[i], CustomvehicleModels[i]);
	}
}
void AddToCustomVehicles()
{
	bool SetModel = 0, SetName = 0, done = 0;
	AddTitle("Add");
	AddTextWithBlackListedWords("Model", GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(CustomvehicleModels[customVehiclesCount]), 0, SetModel);
	AddTextWithBlackListedWords("Name", CustomVehicleNames[customVehiclesCount], 0, SetName);
	AddOption("Done", done);

	if (SetModel)
	{
		CustomvehicleModels[customVehiclesCount] = GET_HASH_KEY(showKeyboard());
		if (!IS_MODEL_IN_CDIMAGE(CustomvehicleModels[customVehiclesCount]))
		{
			PrintBottomLeft("~r~ERROR: ~s~Invalid model");
			CustomvehicleModels[customVehiclesCount] = 0;
			return;
		}
		if (DOES_TEXT_LABEL_EXIST(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(CustomvehicleModels[customVehiclesCount])) && CustomVehicleNames[customVehiclesCount] == "NULL")
		{
			CustomVehicleNames[customVehiclesCount] = _GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(CustomvehicleModels[customVehiclesCount]));
		}
		for (int i = 0; i < customVehiclesCount; i++)
		{
			PrintDebugMessage(AddStrings(Convert::ToString(i), CustomVehicleNames[i]));
		}
	}

	if (SetName)
	{
		CustomVehicleNames[customVehiclesCount] = showKeyboard();
	}

	if (done)
	{
		customVehiclesCount++;
		menu::SetSub_previous();
	}
}
void DeleteFromCustomVehicles()
{
	AddTitle("Delete");
}
void PegasusP()

{

	Vector3 coords = GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER_PED_ID(), 0.0, 5.0, 0.0);

	bool rhino = 0, shamal = 0, mallard = 0, cuban = 0, duster = 0, luxor = 0, frogger = 0, maverick = 0, barracks = 0, squalo = 0, seashark = 0, buzzard = 0, annihilator = 0, mammatus = 0, velum = 0, titan = 0, dump = 0, journey = 0, mule = 0, stretch = 0, speeder = 0, vestra = 0, liberator = 0, besra = 0, miljet = 0, swift = 0, dodo = 0, marshall = 0, savage = 0, valkyrie = 0, hydra = 0, insurgent = 0, LuxorDeluxe = 0, SwiftDeluxe = 0;

	AddTitle("PEGASUS PREMIUM");
	AddBreak("Select a vehicle to have delivered    FREE");
	AddOption("Rhino Tank", rhino);
	AddOption("Shamal", shamal);
	AddOption("Mallard", mallard);
	AddOption("Cuban 800", cuban);
	AddOption("Duster", duster);
	AddOption("Luxor", luxor);
	AddOption("Frogger", frogger);
	AddOption("Maverick", maverick);
	AddOption("Barracks", barracks);
	AddOption("Squalo", squalo);
	AddOption("Seashark", seashark);
	AddOption("Buzzard Attack Chopper", buzzard);
	AddOption("Annihilator", annihilator);
	AddOption("Mammatus", mammatus);
	AddOption("Velum", velum);
	AddOption("Titan", titan);
	AddOption("Dump", dump);
	AddOption("Journey", journey);
	AddOption("Mule", mule);
	AddOption("Stretch", stretch);
	AddOption("Speeder", speeder);
	AddOption("Vestra", vestra);
	AddOption("Liberator", liberator);
	AddOption("Besra", besra);
	AddOption("Miljet", miljet);
	AddOption("Swift", swift);
	AddOption("Dodo", dodo);
	AddOption("Marshall", marshall);
	AddOption("Savage", savage);
	AddOption("Valkyrie", valkyrie);
	AddOption("Hydra", hydra);
	AddOption("Insurgent Pick-Up", insurgent);
	AddOption("Luxor Deluxe", LuxorDeluxe);
	AddOption("Swift Deluxe", SwiftDeluxe);

	if (menujustopened)
	{
		PrintBottomLeft(AddStrings("Thanks for purchasing ", "Pegasus Premium.")); // Your opening message goes here.
		menujustopened = false;
	}

	if (rhino){
		REQUEST_MODEL(GET_HASH_KEY("RHINO"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("RHINO"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("RHINO"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Rhino Tank ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("RHINO"));
		return;
	}

	if (shamal){
		REQUEST_MODEL(GET_HASH_KEY("SHAMAL"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("SHAMAL"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("SHAMAL"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Shamal ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("SHAMAL"));
		return;
	}

	if (mallard){
		REQUEST_MODEL(GET_HASH_KEY("STUNT"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("STUNT"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("STUNT"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Mallard ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("STUNT"));
		return;
	}

	if (cuban){
		REQUEST_MODEL(GET_HASH_KEY("CUBAN800"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("CUBAN800"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("CUBAN800"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Cuban 800 ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("CUBAN800"));
		return;
	}

	if (duster){
		REQUEST_MODEL(GET_HASH_KEY("DUSTER"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("DUSTER"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("DUSTER"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Duster ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("DUSTER"));
		return;
	}

	if (luxor){
		REQUEST_MODEL(GET_HASH_KEY("LUXOR"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("LUXOR"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("LUXOR"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Luxor ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("LUXOR"));
		return;
	}

	if (frogger){
		REQUEST_MODEL(GET_HASH_KEY("FROGGER"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("FROGGER"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("FROGGER"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Frogger ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("FROGGER"));
		return;
	}

	if (maverick){
		REQUEST_MODEL(GET_HASH_KEY("MAVERICK"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("MAVERICK"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("MAVERICK"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Maverick ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("MAVERICK"));
		return;
	}

	if (barracks){
		REQUEST_MODEL(GET_HASH_KEY("BARRACKS"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("BARRACKS"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("BARRACKS"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Barracks ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("BARRACKS"));
		return;
	}

	if (squalo){
		REQUEST_MODEL(GET_HASH_KEY("SQUALO"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("SQUALO"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("SQUALO"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Squalo ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("SQUALO"));
		return;
	}

	if (seashark){
		REQUEST_MODEL(GET_HASH_KEY("SEASHARK"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("SEASHARK"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("SEASHARK"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Seashark ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("SEASHARK"));
		return;
	}

	if (buzzard){
		REQUEST_MODEL(GET_HASH_KEY("BUZZARD"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("BUZZARD"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("BUZZARD"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Buzzard ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("BUZZARD"));
		return;
	}

	if (annihilator){
		REQUEST_MODEL(GET_HASH_KEY("ANNIHILATOR"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("ANNIHILATOR"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("ANNIHILATOR"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Annihilator ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("ANNIHILATOR"));
		return;
	}

	if (mammatus){
		REQUEST_MODEL(GET_HASH_KEY("MAMMATUS"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("MAMMATUS"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("MAMMATUS"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Mammatus ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("MAMMATUS"));
		return;
	}

	if (velum){
		REQUEST_MODEL(GET_HASH_KEY("VELUM"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("VELUM"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("VELUM"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Velum ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("VELUM"));
		return;
	}

	if (titan){
		REQUEST_MODEL(GET_HASH_KEY("TITAN"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("TITAN"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("TITAN"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Titan ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("TITAN"));
		return;
	}

	if (dump){
		REQUEST_MODEL(GET_HASH_KEY("DUMP"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("DUMP"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("DUMP"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Dump ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("DUMP"));
		return;
	}

	if (journey){
		REQUEST_MODEL(GET_HASH_KEY("JOURNEY"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("JOURNEY"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("JOURNEY"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Journey ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("JOURNEY"));
		return;
	}

	if (mule){
		REQUEST_MODEL(GET_HASH_KEY("MULE"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("MULE"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("MULE"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Mule ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("MULE"));
		return;
	}

	if (stretch){
		REQUEST_MODEL(GET_HASH_KEY("STRETCH"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("STRETCH"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("STRETCH"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Stretch ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("STRETCH"));
		return;
	}

	if (speeder){
		REQUEST_MODEL(GET_HASH_KEY("SPEEDER"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("SPEEDER"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("SPEEDER"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Speeder ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("SPEEDER"));
		return;
	}

	if (vestra){
		REQUEST_MODEL(GET_HASH_KEY("VESTRA"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("VESTRA"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("VESTRA"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Vestra ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("VESTRA"));
		return;
	}

	if (liberator){
		REQUEST_MODEL(GET_HASH_KEY("MONSTER"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("MONSTER"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("MONSTER"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Liberator ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("MONSTER"));
		return;
	}

	if (besra){
		REQUEST_MODEL(GET_HASH_KEY("BESRA"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("BESRA"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("BESRA"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Besra ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("BESRA"));
		return;
	}

	if (miljet){
		REQUEST_MODEL(GET_HASH_KEY("MILJET"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("MILJET"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("MILJET"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Miljet ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("MILJET"));
		return;
	}

	if (swift){
		REQUEST_MODEL(GET_HASH_KEY("SWIFT"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("SWIFT"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("SWIFT"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Swift ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("SWIFT"));
		return;
	}

	if (dodo){
		REQUEST_MODEL(GET_HASH_KEY("DODO"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("DODO"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("DODO"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Dodo ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("DODO"));
		return;
	}

	if (marshall){
		REQUEST_MODEL(GET_HASH_KEY("MARSHALL"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("MARSHALL"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("MARSHALL"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Marshall ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("MARSHALL"));
		return;
	}

	if (savage){
		REQUEST_MODEL(GET_HASH_KEY("SAVAGE"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("SAVAGE"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("SAVAGE"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Savage ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("SAVAGE"));
		return;
	}
	if (valkyrie){
		REQUEST_MODEL(GET_HASH_KEY("VALKYRIE"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("VALKYRIE"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("VALKYRIE"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Valkyrie ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("VALKYRIE"));
		return;
	}

	if (hydra){
		REQUEST_MODEL(GET_HASH_KEY("HYDRA"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("HYDRA"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("HYDRA"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Hydra ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("HYDRA"));
		return;
	}

	if (insurgent){
		REQUEST_MODEL(GET_HASH_KEY("INSURGENT"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("INSURGENT"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("INSURGENT"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		PrintBottomLeft(AddStrings("Insurgent Pick-Up ", "Delivered."));
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("INSURGENT"));
		return;
	}

	if (LuxorDeluxe){
		REQUEST_MODEL(GET_HASH_KEY("LUXOR2"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("LUXOR2"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("LUXOR2"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("LUXOR2"));
		PrintBottomLeft(AddStrings("Luxor Deluxe ", "Delivered."));
		return;
	}

	if (SwiftDeluxe){
		REQUEST_MODEL(GET_HASH_KEY("SWIFT2"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("SWIFT2"))) WAIT(0);
		{
			CREATE_VEHICLE(GET_HASH_KEY("SWIFT2"), coords.x, coords.y, coords.z, 0.0, 1, 1);
		}
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("SWIFT2"));
		PrintBottomLeft(AddStrings("Swift Deluxe ", "Delivered."));
		return;
	}





}

void ILLGOTTENGAINS_vehicles()

{
	Vector3 myPos = GET_ENTITY_COORDS(PLAYER_PED_ID(), 0);

	bool StirlingGT = 0, LuxorDeluxe = 0, Osiris = 0, Virgo = 0, SwiftDeluxe = 0, Windsor = 0;

	AddTitle("ILL-GOTTEN GAINS");
	AddOption("Stirling GT", StirlingGT);
	AddOption("Luxor Deluxe", LuxorDeluxe);
	AddOption("Pegassi Osiris", Osiris);
	AddOption("Virgo", Virgo);
	AddOption("Swift Deluxe", SwiftDeluxe);
	AddOption("Windsor", Windsor);

	if (StirlingGT){
		REQUEST_MODEL(GET_HASH_KEY("STIRLING"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("STIRLING"))) WAIT(0);
		{
			Vehicle veh = CREATE_VEHICLE(GET_HASH_KEY("STIRLING"), myPos.x, myPos.y, myPos.z, GET_ENTITY_HEADING(PLAYER_PED_ID()), 0, 0);
			SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), veh, -1); //-1 = seat index
		}
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("STIRLING"));
		return;
	}

	if (LuxorDeluxe){
		REQUEST_MODEL(GET_HASH_KEY("LUXOR2"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("LUXOR2"))) WAIT(0);
		{
			Vehicle veh = CREATE_VEHICLE(GET_HASH_KEY("LUXOR2"), myPos.x, myPos.y, myPos.z, GET_ENTITY_HEADING(PLAYER_PED_ID()), 0, 0);
			SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), veh, -1); //-1 = seat index
		}
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("LUXOR2"));
		return;
	}

	if (Osiris){
		REQUEST_MODEL(GET_HASH_KEY("OSIRIS"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("OSIRIS"))) WAIT(0);
		{
			Vehicle veh = CREATE_VEHICLE(GET_HASH_KEY("OSIRIS"), myPos.x, myPos.y, myPos.z, GET_ENTITY_HEADING(PLAYER_PED_ID()), 0, 0);
			SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), veh, -1); //-1 = seat index
		}
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("OSIRIS"));
		return;
	}

	if (Virgo){
		REQUEST_MODEL(GET_HASH_KEY("VIRGO"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("VIRGO"))) WAIT(0);
		{
			Vehicle veh = CREATE_VEHICLE(GET_HASH_KEY("VIRGO"), myPos.x, myPos.y, myPos.z, GET_ENTITY_HEADING(PLAYER_PED_ID()), 0, 0);
			SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), veh, -1); //-1 = seat index
		}
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("VIRGO"));
		return;
	}

	if (SwiftDeluxe){
		REQUEST_MODEL(GET_HASH_KEY("SWIFT2"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("SWIFT2"))) WAIT(0);
		{
			Vehicle veh = CREATE_VEHICLE(GET_HASH_KEY("SWIFT2"), myPos.x, myPos.y, myPos.z, GET_ENTITY_HEADING(PLAYER_PED_ID()), 0, 0);
			SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), veh, -1); //-1 = seat index
		}
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("SWIFT2"));
		return;
	}

	if (Windsor){
		REQUEST_MODEL(GET_HASH_KEY("WINDSOR"));
		while (!HAS_MODEL_LOADED(GET_HASH_KEY("WINDSOR"))) WAIT(0);
		{
			Vehicle veh = CREATE_VEHICLE(GET_HASH_KEY("WINDSOR"), myPos.x, myPos.y, myPos.z, GET_ENTITY_HEADING(PLAYER_PED_ID()), 0, 0);
			SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), veh, -1); //-1 = seat index
		}
		SET_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY("WINDSOR"));
		return;
	}



}

void ModelChanger()

{

	bool franklin = 0, michael = 0, trevor = 0, alien = 0, customInput = 0;

	AddTitle("Model Changer");
	AddKeyboard("Custom Input", customInput);
	AddOption("Michael", michael);
	AddOption("Franklin", franklin);
	AddOption("Trevor", trevor);
	AddOption("Alien", alien);

	if (michael){
		SetPlayerModel("Player_Zero");
		return;
	}

	if (franklin){
		SetPlayerModel("Player_One");
		return;
	}

	if (trevor){
		SetPlayerModel("Player_Two");
		return;
	}

	if (alien){
		SetPlayerModel("S_M_M_MovAlien_01");
		return;
	}

	if (customInput){
			char* Result = GET_ONSCREEN_KEYBOARD_RESULT();
			if (IS_MODEL_IN_CDIMAGE(GET_HASH_KEY(Result)))
			{
				SetPlayerModel(Result);
			}
			else
			{
				PrintBottomLeft("~r~Error ~s~Invalid model");
			}
	}




}
void iplLoader()

{


	AddTitle("Ipl Loader");
	AddOption("North Yankton", null, nullFunc, SUB::NORTHYANKTON);
	AddOption("Yacht", null, nullFunc, SUB::YACHT);
	AddOption("Heist Yacht", null, nullFunc, SUB::HYACT);
	AddOption("Heist Carrier", null, nullFunc, SUB::HCARRIER);
	AddOption("Destroyed hosptal", null, nullFunc, SUB::DHOSPITAL);
	AddOption("Jewelry Store", null, nullFunc, SUB::JSTORE);
	AddOption("Morgue", null, nullFunc, SUB::MORGUE);
	AddOption("Cargo Ship", null, nullFunc, SUB::CSHIP);
	AddOption("O'Neil Ranch", null, nullFunc, SUB::ONRANCH);
	AddOption("Burnt O'Neil Ranch", null, nullFunc, SUB::BONRANCH);
	AddOption("LifeInvader Lobby", null, nullFunc, SUB::LLOBBY);
	AddOption("FIB Lobby", null, nullFunc, SUB::FIBLOBBY);
	AddOption("Train Crash", null, nullFunc, SUB::TCRASH);
	AddOption("Broken Stilt House", null, nullFunc, SUB::BSHOUSE);
	AddOption("Plane Crash", null, nullFunc, SUB::PCRASH);
	AddOption("Cluckin bell", null, nullFunc, SUB::CBELL);
	AddOption("UFO", null, nullFunc, SUB::UFO);
	//AddOption("Bahama mamas", null, nullFunc, SUB::BAHAMAMAMAS);



}

void NorthYankton()

{
	bool loadny = 0, unloadny = 0;

	AddTitle("North Yankton");
	AddOption("Load", loadny);
	AddOption("Unload", unloadny);
	AddTele("Teleport", 3360.19f, -4849.67f, 111.8f);

	if (loadny){
		REQUEST_IPL("prologue01");
		REQUEST_IPL("prologue01c");
		REQUEST_IPL("prologue01d");
		REQUEST_IPL("prologue01e");
		REQUEST_IPL("prologue01f");
		REQUEST_IPL("prologue01g");
		REQUEST_IPL("prologue01h");
		REQUEST_IPL("prologue01i");
		REQUEST_IPL("prologue01j");
		REQUEST_IPL("prologue01k");
		REQUEST_IPL("prologue01z");
		REQUEST_IPL("prologue02");
		REQUEST_IPL("prologue03");
		REQUEST_IPL("prologue03b");
		REQUEST_IPL("prologue04");
		REQUEST_IPL("prologue04b");
		REQUEST_IPL("prologue05");
		REQUEST_IPL("prologue05b");
		REQUEST_IPL("prologue06");
		REQUEST_IPL("prologue06b");
		REQUEST_IPL("prologuerd");
		REQUEST_IPL("prologuerdb");
		REQUEST_IPL("prologue_m2_door");
		REQUEST_IPL("prologue_LODLights");
		REQUEST_IPL("prologue_DistantLights");
		return;
	}

	if (unloadny){
		REMOVE_IPL("prologue01");
		REMOVE_IPL("prologue01c");
		REMOVE_IPL("prologue01d");
		REMOVE_IPL("prologue01e");
		REMOVE_IPL("prologue01f");
		REMOVE_IPL("prologue01g");
		REMOVE_IPL("prologue01h");
		REMOVE_IPL("prologue01i");
		REMOVE_IPL("prologue01j");
		REMOVE_IPL("prologue01k");
		REMOVE_IPL("prologue01z");
		REMOVE_IPL("prologue02");
		REMOVE_IPL("prologue03");
		REMOVE_IPL("prologue03b");
		REMOVE_IPL("prologue04");
		REMOVE_IPL("prologue04b");
		REMOVE_IPL("prologue05");
		REMOVE_IPL("prologue05b");
		REMOVE_IPL("prologue06");
		REMOVE_IPL("prologue06b");
		REMOVE_IPL("prologuerd");
		REMOVE_IPL("prologuerdb");
		REMOVE_IPL("prologue_m2_door");
		REMOVE_IPL("prologue_LODLights");
		REMOVE_IPL("prologue_DistantLights");
		return;
	}



}

void Yacht()

{
	bool loadyacht = 0, unloadyacht = 0;

	AddTitle("Yacht");
	AddOption("Load", loadyacht);
	AddOption("Unload", unloadyacht);
	AddTele("Teleport", -2045.8f, -1031.2f, 11.9f);

	if (loadyacht){
		REQUEST_IPL("smboat");
		return;
	}

	if (unloadyacht){
		REMOVE_IPL("smboat");
		return;
	}




}

void HYacht()

{

	bool loadhyacht = 0, unloadhyacht = 0;

	AddTitle("Heist Yacht");
	AddOption("Load", loadhyacht);
	AddOption("Unload", unloadhyacht);
	AddTele("Teleport", -2045.8f, -1031.2f, 11.9f);

	if (loadhyacht){
		REQUEST_IPL("hei_yacht_heist");
		REQUEST_IPL("hei_yacht_heist_Bar");
		REQUEST_IPL("hei_yacht_heist_Bedrm");
		REQUEST_IPL("hei_yacht_heist_Bridge");
		REQUEST_IPL("hei_yacht_heist_DistantLights");
		REQUEST_IPL("hei_yacht_heist_enginrm");
		REQUEST_IPL("hei_yacht_heist_LODLights");
		REQUEST_IPL("hei_yacht_heist_Lounge");
		return;
	}

	if (unloadhyacht){
		REMOVE_IPL("hei_yacht_heist");
		REMOVE_IPL("hei_yacht_heist_Bar");
		REMOVE_IPL("hei_yacht_heist_Bedrm");
		REMOVE_IPL("hei_yacht_heist_Bridge");
		REMOVE_IPL("hei_yacht_heist_DistantLights");
		REMOVE_IPL("hei_yacht_heist_enginrm");
		REMOVE_IPL("hei_yacht_heist_LODLights");
		REMOVE_IPL("hei_yacht_heist_Lounge");
		return;
	}



}

void HCarrier()

{
	bool loadhcarrier = 0, unloadhcarrier = 0;

	AddTitle("Heist Carrier");
	AddOption("Load", loadhcarrier);
	AddOption("Unload", unloadhcarrier);
	AddTele("Teleport", -3069.9f, -4632.4f, 16.2f);

	if (loadhcarrier){
		REQUEST_IPL("hei_carrier");
		REQUEST_IPL("hei_carrier_DistantLights");
		REQUEST_IPL("hei_Carrier_int1");
		REQUEST_IPL("hei_Carrier_int2");
		REQUEST_IPL("hei_Carrier_int3");
		REQUEST_IPL("hei_Carrier_int4");
		REQUEST_IPL("hei_Carrier_int5");
		REQUEST_IPL("hei_Carrier_int6");
		REQUEST_IPL("hei_carrier_LODLights");
		return;
	}

	if (unloadhcarrier){
		REMOVE_IPL("hei_carrier");
		REMOVE_IPL("hei_carrier_DistantLights");
		REMOVE_IPL("hei_Carrier_int1");
		REMOVE_IPL("hei_Carrier_int2");
		REMOVE_IPL("hei_Carrier_int3");
		REMOVE_IPL("hei_Carrier_int4");
		REMOVE_IPL("hei_Carrier_int5");
		REMOVE_IPL("hei_Carrier_int6");
		REMOVE_IPL("hei_carrier_LODLights");
		return;
	}
		


}

void Dhosptal()

{
	bool loadhosptal = 0, unloadhosptal = 0;

	AddTitle("Destroyed hosptal");
	AddOption("Load", loadhosptal);
	AddOption("Unload", unloadhosptal);
	AddTele("Teleport", 356.8f, -590.1f, 43.3f);

	if (loadhosptal){
		REQUEST_IPL("RC12B_Destroyed");
		REQUEST_IPL("RC12B_HospitalInterior");
		return;
	}

	if (unloadhosptal){
		REMOVE_IPL("RC12B_Destroyed");
		REMOVE_IPL("RC12B_HospitalInterior");
		return;
	}




}

void JStore()

{
	bool loadjstore = 0, unloadjstore = 0;

	AddTitle("Jewelry Store");
	AddOption("Load", loadjstore);
	AddOption("Unload", unloadjstore);
	AddTele("Teleport", -630.4f, -236.7f, 40.0f);

	if (loadjstore){
		REQUEST_IPL("post_hiest_unload");
		REMOVE_IPL("jewel2fake");
		REMOVE_IPL("bh1_16_refurb");
		return;
	}

	if (unloadjstore){
		REMOVE_IPL("post_hiest_unload");
		REQUEST_IPL("jewel2fake");
		REQUEST_IPL("bh1_16_refurb");
		return;
	}


}

void Morgue()

{
	bool loadmorgue = 0, unloadmorgue = 0;

	AddTitle("Morgue");
	AddOption("Load", loadmorgue);
	AddOption("Unload", unloadmorgue);
	AddTele("Teleport", 244.9f, -1374.7f, 39.5f);

	if (loadmorgue){
		REQUEST_IPL("Coroner_Int_on");
		return;
	}

	if (unloadmorgue){
		REMOVE_IPL("Coroner_Int_on");
		return;
	}



}

void CShip()

{
	bool loadcship = 0, unloadcship = 0;

	AddTitle("Cargo Ship");
	AddOption("Load", loadcship);
	AddOption("Unload", unloadcship);
	AddTele("Teleport", -90.0f, -2365.8f, 14.3f);

	if (loadcship){
		REQUEST_IPL("cargoship");
		return;
	}

	if (unloadcship){
		REMOVE_IPL("cargoship");
		return;
	}



}

void ONRanch()

{
	bool loadonranch = 0, unloadonranch = 0;

	AddTitle("O'Neil Ranch");
	AddOption("Load", loadonranch);
	AddOption("Unload", unloadonranch);
	AddTele("Teleport", 2441.2f, 4968.5f, 51.7f);

	if (loadonranch){
		REQUEST_IPL("farm");
		REQUEST_IPL("farm_props");
		REQUEST_IPL("farmint");
		REMOVE_IPL("farmint_cap");
		return;
	}

	if (unloadonranch){
		REMOVE_IPL("farm");
		REMOVE_IPL("farm_props");
		REMOVE_IPL("farmint");
		REQUEST_IPL("farmint_cap");
		return;
	}



}

void BONRanch()

{
	bool loadbonranch = 0, unloadbonranch = 0;

	AddTitle("Burnt O'Neil Ranch");
	AddOption("Load", loadbonranch);
	AddOption("Unload", unloadbonranch);
	AddTele("Teleport", 2441.2f, 4968.5f, 51.7f);

	if (loadbonranch){
		REQUEST_IPL("farm_burnt");
		REQUEST_IPL("farm_burnt_props");
		return;
	}

	if (unloadbonranch){
		REMOVE_IPL("farm_burnt");
		REMOVE_IPL("farm_burnt_props");
		return;
	}



}

void LLobby()

{
	bool loadllobby = 0, unloadllobby = 0;

	AddTitle("LifeInvader Lobby");
	AddOption("Load", loadllobby);
	AddOption("Unload", unloadllobby);
	AddTele("Teleport", -1047.9f, -233.0f, 39.0f);

	if (loadllobby){
		REQUEST_IPL("facelobby");
		return;
	}

	if (unloadllobby){
		REMOVE_IPL("facelobby");
		return;
	}



}

void FIB_lobby()

{
	bool loadfib = 0, unloadfib = 0;

	AddTitle("FIB Lobby");
	AddOption("Load", loadfib);
	AddOption("Unload", unloadfib);
	AddTele("Teleport", 110.4f, -744.2f, 45.7f);

	if (loadfib){
		REQUEST_IPL("FIBlobby");
		return;
	}

	if (unloadfib){
		REMOVE_IPL("FIBlobby");
		return;
	}



}

void TCrash()

{
	bool loadtcrash = 0, unloadtcrash = 0;

	AddTitle("Train Crash");
	AddOption("Load", loadtcrash);
	AddOption("Unload", unloadtcrash);
	AddTele("Teleport", -532.1309f, 4526.187f, 88.7955f);

	if (loadtcrash){
		REQUEST_IPL("canyonriver01_traincrash");
		REQUEST_IPL("railing_end​");
		REMOVE_IPL("railing_start");
		REMOVE_IPL("canyonriver01");
		return;
	}

	if (unloadtcrash){
		REMOVE_IPL("canyonriver01_traincrash");
		REMOVE_IPL("railing_end​");
		REQUEST_IPL("railing_start");
		REQUEST_IPL("canyonriver01");
		return;
	}



}

void B_S_House()

{
	bool loadbshouse = 0, unloadbshouse = 0;

	AddTitle("Broken Stilt House");
	AddOption("Load", loadbshouse);
	AddOption("Unload", unloadbshouse);
	AddTele("Teleport", -1020.5f, 663.41f, 154.75f);

	if (loadbshouse){
		REQUEST_IPL("DES_StiltHouse_imapend");
		REMOVE_IPL("DES_StiltHouse_imapstart");
		REMOVE_IPL("des_stilthouse_rebuild");
		return;
	}

	if (unloadbshouse){
		REMOVE_IPL("DES_StiltHouse_imapend");
		REQUEST_IPL("DES_StiltHouse_imapstart");
		REQUEST_IPL("des_stilthouse_rebuild");
		return;
	}


}

void PCrash()

{
	bool loadpcrash = 0, unloadpcrash = 0;

	AddTitle("Plane Crash");
	AddOption("Load", loadpcrash);
	AddOption("Unload", unloadpcrash);
	AddTele("Teleport", 2814.7f, 4758.5f, 50.0f);

	if (loadpcrash){
		REQUEST_IPL("Plane_crash_trench");
		return;
	}

	if (unloadpcrash){
		REMOVE_IPL("Plane_crash_trench");
		return;
	}



}

void CBell()

{
	bool loadcbell = 0, unloadcbell = 0;

	AddTitle("Cluckin bell");
	AddOption("Load", loadcbell);
	AddOption("Unload", unloadcbell);
	AddTele("Teleport", -72.68752f, 6253.72656f, 31.08991f);

	if (loadcbell){
		REMOVE_IPL("CS1_02_cf_offmission");
		REQUEST_IPL("CS1_02_cf_onmission1");
		REQUEST_IPL("CS1_02_cf_onmission2");
		REQUEST_IPL("CS1_02_cf_onmission3");
		REQUEST_IPL("CS1_02_cf_onmission4");
		return;
	}

	if (unloadcbell){
		REQUEST_IPL("CS1_02_cf_offmission");
		REMOVE_IPL("CS1_02_cf_onmission1");
		REMOVE_IPL("CS1_02_cf_onmission2");
		REMOVE_IPL("CS1_02_cf_onmission3");
		REMOVE_IPL("CS1_02_cf_onmission4");
		return;
	}

}

void UFO()

{
	bool loadufo = 0, unloadufo = 0;

	AddTitle("UFO");
	AddOption("Load", loadufo);
	AddOption("Unload", unloadufo);
	AddTele("Teleport to UFO above fort Zancudo", -2051.99463f, 3237.05835f, 1456.97021f);
	AddTele("Teleport to UFO above trevor's airfield", 2490.47729f, 3774.84351f, 2414.035f);

	if (loadufo){
		REQUEST_IPL("ufo");
		return;
	}

	if (unloadufo){
		REMOVE_IPL("ufo");
		return;
	}



}

void BahamaMamas()
{
	bool Load = 0, Unload = 0;
	AddTitle("Bahama Mamas");
	AddOption("Load");
	AddOption("Unload");
	if (Load){
		Any interior = GET_INTERIOR_AT_COORDS(-1390.39, - 617.19, 30.26);
		_0x2CA429C029CCF247(interior);
		SET_INTERIOR_ACTIVE(interior, true);
	}
	if (Unload){
		Any interior = GET_INTERIOR_AT_COORDS(-1390.39, -617.19, 30.26);
		SET_INTERIOR_ACTIVE(interior, false);
	}
}
void ObjectSpawner()

{
	bool ufo = 0, ferris_wheel = 0, customInput = 0, custom1 = 0, custom2 = 0, custom3 = 0, custom4 = 0, custom5 = 0, custom6 = 0, custom7 = 0, custom8 = 0, custom9 = 0, custom10 = 0, deleteall = 0;

	AddTitle("Object Spawner");
	AddOption("Object options", null, nullFunc, SUB::OBJECTOPTIONS);
	AddKeyboard("Custom Input", customInput);
	AddOption("UFO", ufo);
	AddOption("Ferris Wheel", ferris_wheel);
	if (CustomObject1Used) AddOption(ObjectSpawnerCustom1Name, custom1);
	if (CustomObject2Used) AddOption(ObjectSpawnerCustom2Name, custom2);
	if (CustomObject3Used) AddOption(ObjectSpawnerCustom3Name, custom3);
	if (CustomObject4Used) AddOption(ObjectSpawnerCustom4Name, custom4);
	if (CustomObject5Used) AddOption(ObjectSpawnerCustom5Name, custom5);
	if (CustomObject6Used) AddOption(ObjectSpawnerCustom6Name, custom6);
	if (CustomObject7Used) AddOption(ObjectSpawnerCustom7Name, custom7);
	if (CustomObject8Used) AddOption(ObjectSpawnerCustom8Name, custom8);
	if (CustomObject9Used) AddOption(ObjectSpawnerCustom9Name, custom9);
	if (CustomObject10Used) AddOption(ObjectSpawnerCustom10Name, custom10);
	//AddOption("Add Custom", null, nullFunc, SUB::ADDCUSTOMOBJECT);
	AddOption("Delete all spawned objects", deleteall);

	if (ufo){
		CreateObjectInSlot("P_SPINNING_ANUS_S");
		return;
		}

	if (ferris_wheel){
		CreateObjectInSlot("prop_ld_ferris_wheel");
		return;
	}

	if (customInput){
		char* Result = GET_ONSCREEN_KEYBOARD_RESULT();
		if (IS_MODEL_IN_CDIMAGE(GET_HASH_KEY(Result)))
		{
			CreateObjectInSlot(Result);
		}
		else
		{
			PrintBottomLeft(AddStrings(Result, " ~r~Does Not Exist"));
		}
	}

	if (custom1) CreateObjectInSlot(CustomObject1Model);
	if (custom2) CreateObjectInSlot(CustomObject2Model);
	if (custom3) CreateObjectInSlot(CustomObject3Model);
	if (custom4) CreateObjectInSlot(CustomObject4Model);
	if (custom5) CreateObjectInSlot(CustomObject5Model);
	if (custom6) CreateObjectInSlot(CustomObject6Model);
	if (custom7) CreateObjectInSlot(CustomObject7Model);
	if (custom8) CreateObjectInSlot(CustomObject8Model);
	if (custom9) CreateObjectInSlot(CustomObject9Model);
	if (custom10) CreateObjectInSlot(CustomObject10Model);

	if (deleteall){
		for (int i = 0; i < ObjectSpawnerslots; i++)
			if (ObjectSlotUsed[i]){
				SET_ENTITY_AS_MISSION_ENTITY(ObjectSlots[i], true, true);
				DELETE_ENTITY(&ObjectSlots[i]);
				ObjectSlotsName[i] = "";
				ObjectSlotUsed[i] = 0;
			}
	}

}
void ObjectOptions()
{
	AddTitle("Object options");
	for (int i = 0; i < ObjectSpawnerslots; i++)
		_AddObjectOption(i);
}
void AddRotation(char* text, float pitch, float roll, float yaw)
{
	null = 0;
	AddOption(text, null);
	if (null)
	{
		SET_ENTITY_ROTATION(ObjectSlot, GET_ENTITY_PITCH(ObjectSlot) + pitch, GET_ENTITY_ROLL(ObjectSlot) + roll, GET_ENTITY_ROTATION(ObjectSlot, false).z + yaw, 4, 1);
	}
}
void Object()
{
	Vector3 ObjectCoords = GET_ENTITY_COORDS(ObjectSlot, false);
	bool MoveUp = 0, MoveDown = 0, MoveX = 0, MoveY = 0, MoveXm = 0, MoveYm = 0, deleteObject = 0, freeze = 0, unfreeze = 0, duplicate = 0;
	AddTitle(ObjecSlotName);
	AddOption("X+", MoveX);
	AddOption("X-", MoveXm);
	AddOption("Y+", MoveY);
	AddOption("Y-", MoveYm);
	AddOption("Z+", MoveUp);
	AddOption("Z-", MoveDown);
	AddRotation("Pitch+", 1.0f, 0, 0);
	AddRotation("Pitch-", -1.0f, 0, 0);
	AddRotation("Roll+", 0, 1.0f, 0);
	AddRotation("Roll-", 0, -1.0f, 0);
	AddRotation("Yaw+", 0, 0, 1.0f);
	AddRotation("Yaw-", 0, 0, -1.0f);
	AddOption("Freeze", freeze);
	AddOption("Unfreeze", unfreeze);
	AddOption("Duplicate", duplicate);
	AddOption("Delete", deleteObject);
	if (MoveX) SET_ENTITY_COORDS(ObjectSlot, ObjectCoords.x + 1.0f, ObjectCoords.y, ObjectCoords.z, 0, 0, 0, 1);
	if (MoveXm) SET_ENTITY_COORDS(ObjectSlot, ObjectCoords.x - 1.0f, ObjectCoords.y, ObjectCoords.z, 0, 0, 0, 1);
	if (MoveY) SET_ENTITY_COORDS(ObjectSlot, ObjectCoords.x, ObjectCoords.y + 1.0f, ObjectCoords.z, 0, 0, 0, 1);
	if (MoveYm) SET_ENTITY_COORDS(ObjectSlot, ObjectCoords.x, ObjectCoords.y - 1.0f, ObjectCoords.z, 0, 0, 0, 1);
	if (MoveUp) SET_ENTITY_COORDS(ObjectSlot, ObjectCoords.x, ObjectCoords.y, ObjectCoords.z + 1.0f, 0, 0, 0, 1);
	if (MoveDown) SET_ENTITY_COORDS(ObjectSlot, ObjectCoords.x, ObjectCoords.y, ObjectCoords.z - 1.0f, 0, 0, 0, 1);
	if (freeze) FREEZE_ENTITY_POSITION(ObjectSlot, true);
	if (unfreeze) FREEZE_ENTITY_POSITION(ObjectSlot, false);
	if (deleteObject) {
		SET_ENTITY_AS_MISSION_ENTITY(ObjectSlot, true, true); DELETE_OBJECT(&ObjectSlot);
		ObjectSlotUsed[SelectedObject] = 0; ObjectSlotsName[SelectedObject] = "";
		menu::SetSub_previous();
	}
	if (duplicate)
	{
		CreateObjectInSlot(ObjectSlotsName[SelectedObject]);
	}
}
void AddCustomObject()
{
	bool name = 0, model = 0, add = 0;
	AddTitle("Add Custom");
	AddKeyboard("Object Name", name);
	AddKeyboard("Object Model", model);
	AddOption("Add", add);

	if (name){
		if (!CustomObject1Used){ ObjectSpawnerCustom1Name = GET_ONSCREEN_KEYBOARD_RESULT(); }
		else if (!CustomObject2Used){ ObjectSpawnerCustom2Name = GET_ONSCREEN_KEYBOARD_RESULT(); }
		else if (!CustomObject3Used){ ObjectSpawnerCustom3Name = GET_ONSCREEN_KEYBOARD_RESULT(); }
		else if (!CustomObject4Used){ ObjectSpawnerCustom4Name = GET_ONSCREEN_KEYBOARD_RESULT(); }
		else if (!CustomObject5Used){ ObjectSpawnerCustom5Name = GET_ONSCREEN_KEYBOARD_RESULT(); }
		else if (!CustomObject6Used){ ObjectSpawnerCustom6Name = GET_ONSCREEN_KEYBOARD_RESULT(); }
		else if (!CustomObject7Used){ ObjectSpawnerCustom7Name = GET_ONSCREEN_KEYBOARD_RESULT(); }
		else if (!CustomObject8Used){ ObjectSpawnerCustom8Name = GET_ONSCREEN_KEYBOARD_RESULT(); }
		else if (!CustomObject9Used){ ObjectSpawnerCustom9Name = GET_ONSCREEN_KEYBOARD_RESULT(); }
		else if (!CustomObject10Used){ ObjectSpawnerCustom10Name = GET_ONSCREEN_KEYBOARD_RESULT(); }
		else { if (DebugMode) PrintBottomLeft("~r~Error"); }
		return;
	}

	if (model){
		if (!CustomObject1Used){ CustomObject1Model = GET_ONSCREEN_KEYBOARD_RESULT(); }
		else if (!CustomObject2Used){ CustomObject2Model = GET_ONSCREEN_KEYBOARD_RESULT(); }
		else if (!CustomObject3Used){ CustomObject3Model = GET_ONSCREEN_KEYBOARD_RESULT(); }
		else if (!CustomObject4Used){ CustomObject4Model = GET_ONSCREEN_KEYBOARD_RESULT(); }
		else if (!CustomObject5Used){ CustomObject5Model = GET_ONSCREEN_KEYBOARD_RESULT(); }
		else if (!CustomObject6Used){ CustomObject6Model = GET_ONSCREEN_KEYBOARD_RESULT(); }
		else if (!CustomObject7Used){ CustomObject7Model = GET_ONSCREEN_KEYBOARD_RESULT(); }
		else if (!CustomObject8Used){ CustomObject8Model = GET_ONSCREEN_KEYBOARD_RESULT(); }
		else if (!CustomObject9Used){ CustomObject9Model = GET_ONSCREEN_KEYBOARD_RESULT(); }
		else if (!CustomObject10Used){ CustomObject10Model = GET_ONSCREEN_KEYBOARD_RESULT(); }
		else PrintBottomLeft("~r~Error");
		return;
	}

	if (add){
		if (!CustomObject1Used){ if (ObjectSpawnerCustom1Name == "") PrintBottomLeft("~r~ERROR: ~s~Name is missing"); else if (CustomObject1Model == "") PrintBottomLeft("~r~ERROR: ~s~Model is missing"); else{ CustomObject1Used = 1; menu::SetSub_previous(); } }
		else if (!CustomObject2Used){ if (ObjectSpawnerCustom2Name == "") PrintBottomLeft("~r~ERROR: ~s~Name is missing"); else if (CustomObject2Model == "") PrintBottomLeft("~r~ERROR: ~s~Model is missing"); else{ CustomObject2Used = 1; menu::SetSub_previous(); } }
		else if (!CustomObject3Used){ if (ObjectSpawnerCustom3Name == "") PrintBottomLeft("~r~ERROR: ~s~Name is missing"); else if (CustomObject3Model == "") PrintBottomLeft("~r~ERROR: ~s~Model is missing"); else{ CustomObject3Used = 1; menu::SetSub_previous(); } }
		else if (!CustomObject4Used){ if (ObjectSpawnerCustom4Name == "") PrintBottomLeft("~r~ERROR: ~s~Name is missing"); else if (CustomObject4Model == "") PrintBottomLeft("~r~ERROR: ~s~Model is missing"); else{ CustomObject4Used = 1; menu::SetSub_previous(); } }
		else if (!CustomObject5Used){ if (ObjectSpawnerCustom5Name == "") PrintBottomLeft("~r~ERROR: ~s~Name is missing"); else if (CustomObject5Model == "") PrintBottomLeft("~r~ERROR: ~s~Model is missing"); else{ CustomObject5Used = 1; menu::SetSub_previous(); } }
		else if (!CustomObject6Used){ if (ObjectSpawnerCustom6Name == "") PrintBottomLeft("~r~ERROR: ~s~Name is missing"); else if (CustomObject6Model == "") PrintBottomLeft("~r~ERROR: ~s~Model is missing"); else{ CustomObject6Used = 1; menu::SetSub_previous(); } }
		else if (!CustomObject7Used){ if (ObjectSpawnerCustom7Name == "") PrintBottomLeft("~r~ERROR: ~s~Name is missing"); else if (CustomObject7Model == "") PrintBottomLeft("~r~ERROR: ~s~Model is missing"); else{ CustomObject7Used = 1; menu::SetSub_previous(); } }
		else if (!CustomObject8Used){ if (ObjectSpawnerCustom8Name == "") PrintBottomLeft("~r~ERROR: ~s~Name is missing"); else if (CustomObject8Model == "") PrintBottomLeft("~r~ERROR: ~s~Model is missing"); else{ CustomObject8Used = 1; menu::SetSub_previous(); } }
		else if (!CustomObject9Used){ if (ObjectSpawnerCustom9Name == "") PrintBottomLeft("~r~ERROR: ~s~Name is missing"); else if (CustomObject9Model == "") PrintBottomLeft("~r~ERROR: ~s~Model is missing"); else{ CustomObject9Used = 1; menu::SetSub_previous(); } }
		else if (!CustomObject10Used){ if (ObjectSpawnerCustom10Name == "") PrintBottomLeft("~r~ERROR: ~s~Name is missing"); else if (CustomObject10Model == "") PrintBottomLeft("~r~ERROR: ~s~Model is missing"); else{ CustomObject10Used = 1; menu::SetSub_previous(); } }
		else PrintBottomLeft("~r~Error");
		return;
	}
}
void PedSpawnMenu()
{


	bool Michael = 0, franklin = 0, trevor = 0, swat = 0, cop = 0, alien = 0, customInput = 0;

	AddTitle("Ped Spawner");
	AddOption("Ped Options", null, nullFunc, SUB::PEDOPTIONS);
	AddOption("Michael", Michael);
	AddOption("Franklin", franklin);
	AddOption("Trevor", trevor);
	AddOption("Swat", swat);
	AddOption("Cop", cop);
	AddOption("Alien", alien);
	AddKeyboard("Custom Input", customInput);
	AddOption("Settings", null, nullFunc, SUB::PEDSPAWNERSETTINGS);

	if (Michael){
		SpawnPedinSlot("player_zero", "Michael");
		return;
	}

	if (franklin){
		SpawnPedinSlot("player_one", "Franklin");
		return;
	}

	if (trevor){
		SpawnPedinSlot("player_two", "Trevor");
		return;
	}

	if (swat){
		SpawnPedinSlot("s_m_y_swat_01", "Swat");
		return;
	}

	if (cop){
		SpawnPedinSlot("s_m_y_cop_01", "Cop");
		return;
	}

	if (alien){
		SpawnPedinSlot("s_m_m_movalien_01", "Alien");
		return;
	}

	if (customInput){
		char* Result = GET_ONSCREEN_KEYBOARD_RESULT();
		if (IS_MODEL_IN_CDIMAGE(GET_HASH_KEY(Result)))
		{
			SpawnPedinSlot(Result, Result);
		}
		else
		{
			PrintBottomLeft(AddStrings(Result, " is ~r~Invalid"));
		}
	}




}

void PedOptions()
{
	AddTitle("Ped Options");
	for (int i = 0; i < PedSpawnerSlots; i++)
		AddPedMenu(i);

}
void Ped()
{
	if (!DOES_ENTITY_EXIST(PED1)) menu::SetSub_previous();
	bool SetAsBodyguard = 0, teleportto = 0, teleporttome = 0, GiveAllWeapons = 0, takeallweapons = 0, deletePed = 0, freezepedON = 0, freezepedOFF = 0;

	AddTitle(NameSlot);
	AddOption("Teleport To Ped", teleportto);
	AddOption("Teleport Ped To Me", teleporttome);
	AddOption("Give All Weapons", GiveAllWeapons);
	AddOption("Take All Weapons", takeallweapons);
	AddOption("Set as bodyguard", SetAsBodyguard);
	AddToggle("Freeze ped", FreezePed, freezepedON, freezepedOFF);
	AddOption("XYZ Coords", null, nullFunc, SUB::PEDSPAWNERXYZ);
	AddOption("Delete Ped", deletePed);

	if (teleportto){
		Vector3 PEDPOS = GET_ENTITY_COORDS(PED1, true);
		SET_ENTITY_COORDS(PLAYER_PED_ID(), PEDPOS.x, PEDPOS.y, PEDPOS.z, 0, 0, 0, 1);
		PrintStringBottomCentre(AddStrings("Teleported to ", "Ped"));
		return;
	}

	if (teleporttome){
		Vector3 PLAYERPOS = GET_ENTITY_COORDS(PLAYER_PED_ID(), true);
		SET_ENTITY_COORDS(PED1, PLAYERPOS.x, PLAYERPOS.y, PLAYERPOS.z, 0, 0, 0, 1);
		//PrintStringBottomCentre(AddStrings("Teleported Ped to ", "Me"));
		return;
	}

	if (GiveAllWeapons){
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0xa2719263, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x99b507ea, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x678b81b1, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x4e875f73, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x958a4a8f, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x440e4788, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x84bd7bfd, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x1b06d571, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x5ef9fec4, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x22d8fe39, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x99aeeb3b, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x13532244, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x2be6766b, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0xefe7e2df, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0xbfefff6d, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x83bf0278, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0xaf113f99, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x9d07f764, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x7fd62962, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x1d073a89, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x7846a318, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0xe284c527, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x9d61e50f, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x3656c8c1, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x5fc3c11, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0xc472fe2, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0xa284510b, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x4dd2dc56, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0xb1ca77b1, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x687652ce, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x42bf8a85, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x93e220bd, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x2c3731d9, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0xfdbc8a50, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0xa0973d5e, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x24b17070, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x60ec506, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x34a67b97, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x23c9f95c, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x497facc3, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0xf9e6aa4b, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x61012683, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0xc0a3098d, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0xd205520e, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0xbfd21232, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x7f229f94, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x92a27487, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x83839c4, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0xa89cb99e, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x7f7497e5, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x3aabbbaa, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0xc734385a, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x63ab0442, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0xaf2208a7, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x787f0bb, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0xF9DCBF2D, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(PED1, 0x6D544C99, 9999, 1);
		return;
	}

	if (takeallweapons){
		REMOVE_ALL_PED_WEAPONS(PED1, 1);
		return;
	}

	if (SetAsBodyguard){
		SET_PED_AS_GROUP_MEMBER(PED1, GET_PLAYER_GROUP(PLAYER_PED_ID()));
		return;	
	}

	if (freezepedON) FREEZE_ENTITY_POSITION(PED1, true);
	if (freezepedOFF) FREEZE_ENTITY_POSITION(PED1, false);

	if (deletePed){
				SET_ENTITY_AS_MISSION_ENTITY(PedSlots[SelectedPedSlot], true, true);
				DELETE_PED(&PedSlots[SelectedPedSlot]);
				REMOVE_BLIP(&BlipPedSlots[SelectedPedSlot]);
				PedSlotUsed[SelectedPedSlot] = 0;
				PedNameSlot[SelectedPedSlot] = "";
				menu::SetSub_previous();
		return;
	}
}
void PedSpawnerSettings()
{

	bool DeleteAll = 0;

	AddTitle("Spawner Settings");
	AddToggle("Spawn Invincible", PedSpawnInvincible);
	AddToggle("Spawn As Bodyguard", PedSpawnAsBodyguard);
	AddToggle("Spawn With Blip", PedSpawnWithBlip);
	AddOption("Spawn with weapon", null, nullFunc, SUB::PEDSPAWNERWEAPONSELECTION);
	AddOption("Delete All Spawned Peds", DeleteAll);

	if (DeleteAll){
		for (int i = 0; i < PedSpawnerSlots; i++)
			if (PedSlotUsed[i]){
				SET_ENTITY_AS_MISSION_ENTITY(PedSlots[i], true, true);
				DELETE_PED(&PedSlots[i]);
				REMOVE_BLIP(&BlipPedSlots[i]);
				PedSlotUsed[i] = 0;
				PedNameSlot[i] = "";
			}
		PrintBottomLeft("Peds Deleted");
		return;
	}


}
void PedSpawnerWeaponSelection()
{
	bool CheckAll = 0, UncheckAll = 0;
	AddTitle("Select Weapons");
	AddOption("Check All", CheckAll);
	AddOption("Uncheck All", UncheckAll);
	AddPedWeapon("Knife", 0);
	AddPedWeapon("Nightstick", 1);
	AddPedWeapon("Hammer", 2);
	AddPedWeapon("Baseball Bat", 3);
	AddPedWeapon("Golf Club", 4);
	AddPedWeapon("Cowbar", 5);
	AddPedWeapon("Pistol", 6);
	AddPedWeapon("Combat Pistol", 7);
	AddPedWeapon("AP Pistol", 8);
	AddPedWeapon("Pistol .50", 9);
	AddPedWeapon("Micro SMG", 10);
	AddPedWeapon("SMG", 11);
	AddPedWeapon("Assault SMG", 12);
	AddPedWeapon("Assault Rifle", 13);
	AddPedWeapon("Carbine Rifle", 14);
	AddPedWeapon("Advanced Rifle", 15);
	AddPedWeapon("MG", 16);
	AddPedWeapon("Combat MG", 17);
	AddPedWeapon("Pump Shotgun", 18);
	AddPedWeapon("Sawed-Off Shotgun", 19);
	AddPedWeapon("Assault Shotgun", 20);
	AddPedWeapon("Bullpup Shotgun", 21);
	AddPedWeapon("Stun Gun", 22);
	AddPedWeapon("Sniper Rifle", 23);
	AddPedWeapon("Hevy Sniper", 24);
	AddPedWeapon("Grenade Launcher", 25);
	AddPedWeapon("Smoke Grenade Launcher", 26);
	AddPedWeapon("RPG", 27);
	AddPedWeapon("Minigun", 28);
	AddPedWeapon("Grenade", 29);
	AddPedWeapon("Sticky Bomb", 30);
	AddPedWeapon("Smoke Grenade", 31);
	AddPedWeapon("BZ Gas", 32);
	AddPedWeapon("Molotov", 33);
	AddPedWeapon("Fire Extinguisher", 34);
	AddPedWeapon("Petrol Can", 35);
	AddPedWeapon("SNS Pistol", 36);
	AddPedWeapon("Special Carbine", 37);
	AddPedWeapon("Hevy Pistol", 38);
	AddPedWeapon("Bullup Rifle", 39);
	AddPedWeapon("Homing Launcher", 40);
	AddPedWeapon("Proximity Mine", 41);
	AddPedWeapon("Snowball", 42);
	AddPedWeapon("Vintage Pistol", 43);
	AddPedWeapon("Antique Cavalry Dagger", 44);
	AddPedWeapon("Firework Launcher", 45);
	AddPedWeapon("Musket", 46);
	AddPedWeapon("Marksman Rifle", 47);
	AddPedWeapon("Hevy Shotgun", 48);
	AddPedWeapon("Gusenberg Sweeper", 49);
	AddPedWeapon("Hatchet", 50);
	AddPedWeapon("Railgun", 51);
	AddPedWeapon("Combat pdf", 52);
	AddPedWeapon("Knuckledusters", 53);
	AddPedWeapon("Marksman Pistol", 54);
	if (CheckAll){
		for (int i = 0; i < getArraySize(Array::WeaponModels); i++){
			PedSpawnWithWeapon[i] = 1;
		}
		return;
	}
	if (UncheckAll){
		for (int i = 0; i < getArraySize(Array::WeaponModels) ; i++){
			PedSpawnWithWeapon[i] = 0;
		}
		return;
	}
}
void PedSpawnerSetCoords()
{
	PedSpawnerCoords = GET_ENTITY_COORDS(PED1, true);
	bool coordXp = 0, coordXm = 0, coordYp = 0, coordYm = 0, coordZp = 0, coordZm = 0;

	AddTitle("XYZ coords");
	AddNumber("X", PedSpawnerCoords.x, 0, null, coordXp, coordXm);
	AddNumber("Y", PedSpawnerCoords.y, 0, null, coordYp, coordYm);
	AddNumber("Z", PedSpawnerCoords.z, 0, null, coordZp, coordZm);

	if (coordXp) SET_ENTITY_COORDS(PED1, PedSpawnerCoords.x + 0.05, PedSpawnerCoords.y, PedSpawnerCoords.z, 0, 0, 0, 1);
	if (coordXm) SET_ENTITY_COORDS(PED1, PedSpawnerCoords.x - 0.05, PedSpawnerCoords.y, PedSpawnerCoords.z, 0, 0, 0, 1);
	if (coordYp) SET_ENTITY_COORDS(PED1, PedSpawnerCoords.x, PedSpawnerCoords.y + 0.05, PedSpawnerCoords.z, 0, 0, 0, 1);
	if (coordYm) SET_ENTITY_COORDS(PED1, PedSpawnerCoords.x, PedSpawnerCoords.y - 0.05, PedSpawnerCoords.z, 0, 0, 0, 1);
	if (coordZp) SET_ENTITY_COORDS(PED1, PedSpawnerCoords.x, PedSpawnerCoords.y, PedSpawnerCoords.z + 0.05, 0, 0, 0, 1);
	if (coordZm) SET_ENTITY_COORDS(PED1, PedSpawnerCoords.x, PedSpawnerCoords.y, PedSpawnerCoords.z - 0.05, 0, 0, 0, 1);
}
void Weapons()
{
	bool getall = 0, removeall = 0, unlimitedammoON = 0, unlimitedammoOFF = 0;

	AddTitle("Weapons");
	AddOption("Get All Weapons", getall);
	AddOption("Remove All Weapons", removeall);
	AddToggle("Unlimited Ammo", ammo_check, unlimitedammoON, unlimitedammoOFF);
	AddOption("Custom Bullets", null, nullFunc, SUB::CUSTOMBULLETS);

	if (getall){
		for (int i = 0; i < getArraySize(Array::WeaponModels); i++)
			GIVE_DELAYED_WEAPON_TO_PED(PLAYER_PED_ID(), GET_HASH_KEY(getFromArray(Array::WeaponModels, i)), 9999, 1);
		return;
	}

	if (removeall){
		REMOVE_ALL_PED_WEAPONS(PLAYER_PED_ID(), 1);
		return;
	}

	if (unlimitedammoON){
		SET_PED_INFINITE_AMMO_CLIP(PLAYER_PED_ID(), true);
	    PrintStringBottomCentre(AddStrings("Unlimited ammo  ", "~g~ON"));
		return;
	}

	if (unlimitedammoOFF){
		SET_PED_INFINITE_AMMO_CLIP(PLAYER_PED_ID(), false);
		PrintStringBottomCentre(AddStrings("Unlimited ammo  ", "~r~OFF"));
		return;
	}

}

void CustomBullets()
{
	bool TOMoneyBag = 0, TOVehGun = 0, TORpg = 0, TOTeleGun = 0;

	AddTitle("Custom Bullets");
	AddToggle("Money Bags", CBMoneyBag, TOMoneyBag);
	AddToggle("Vehicles", CBVehGun, TOVehGun);
	AddToggle("Rpg", CBRpg, TORpg);
	AddToggle("Teleport Gun", CBTeleGun, TOTeleGun);

	if (TOMoneyBag){
		customBulletsCheck = true;
		CBVehGun = false;
		CBRpg = false;
		CBTeleGun = false;
		return;
	}

	if (TOVehGun){
		customBulletsCheck = true;
		CBRpg = false;
		CBTeleGun = false;
		CBMoneyBag = false;
		return;
	}

	if (TORpg){
		customBulletsCheck = true;
		CBTeleGun = false;
		CBMoneyBag = false;
		CBVehGun = false;
		return;
	}

	if (TOTeleGun){
		customBulletsCheck = true;
		CBMoneyBag = false;
		CBVehGun = false;
		CBRpg = false;
		return;
	}
	
}
void DevMenu()
{
	bool SetSub = 0;
	AddTitle("Dev Menu");
	AddOption("SetSub", SetSub);

	if (SetSub){
		int Result = GET_ONSCREEN_KEYBOARD_RESULT_INT();
		menu::SetSub_delayed = Result;
	}
}
void Animations()
{
	bool StopAnim = 0;
	AddTitle("Animations");
	AddOption("Stop animations", StopAnim);
	AddAnim("Busted", "busted", "idle_2_hands_up");
	AddAnim("Sit down", "amb@code_human_train_driver@base", "sit");
	AddAnim("Sleep", "misscarsteal4asleep ", "franklin_asleep");
	AddAnim("Suicide", "mp_suicide", "pistol_fp");

	if (StopAnim) CLEAR_PED_TASKS_IMMEDIATELY(PLAYER_PED_ID());
}
void Scenarios()
{
	bool StopScenario = 0, customInput = 0;
	AddTitle("Scenarios");
	AddOption("Stop scenarios", StopScenario);
	AddKeyboard("Custom Input", customInput);
	AddScenario("Smoke", "WORLD_HUMAN_SMOKING");
	AddScenario("Guitar", "WORLD_HUMAN_MUSICIAN");
	AddScenario("Push ups", "WORLD_HUMAN_PUSH_UPS");
	AddScenario("Sit ups", "WORLD_HUMAN_SIT_UPS");
	AddScenario("Fishing", "WORLD_HUMAN_STAND_FISHING");
	AddScenario("Tennis", "WORLD_HUMAN_TENNIS_PLAYER");
	AddScenario("Yoga", "WORLD_HUMAN_YOGA");
	AddScenario("Drink coffee", "WORLD_HUMAN_AA_COFFEE");
	AddScenario("Tennis", "WORLD_HUMAN_TENNIS_PLAYER");

	if (StopScenario) CLEAR_PED_TASKS_IMMEDIATELY(PLAYER_PED_ID());
	if (customInput) TASK_START_SCENARIO_IN_PLACE(PLAYER_PED_ID(), GET_ONSCREEN_KEYBOARD_RESULT(), 0, false);
}
void ComponentChanger()
{
	bool VariationP = 0, VariationM = 0, TextureP = 0, TextureM = 0;

	AddTitle(componentChangerCompmentName);
	AddNumber2("Variation", componentChangerdrawableId, 0, null, VariationP, VariationM);
	AddNumber2("Texture", componentChangerTextureId, 0, null, TextureP, TextureM);

	if (VariationP)
	{
		if (componentChangerdrawableId == GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER_PED_ID(), componentChangerId)){ SET_PED_COMPONENT_VARIATION(PLAYER_PED_ID(), componentChangerId, 0, 0, 2); componentChangerdrawableId = 0; }
		else{ SET_PED_COMPONENT_VARIATION(PLAYER_PED_ID(), componentChangerId, componentChangerdrawableId + 1, 0, 2); componentChangerdrawableId = componentChangerdrawableId + 1; }
		componentChangerTextureId = GET_PED_TEXTURE_VARIATION(PLAYER_PED_ID(), componentChangerId);
	}
	if (VariationM)
	{
		if (componentChangerdrawableId == 0){ SET_PED_COMPONENT_VARIATION(PLAYER_PED_ID(), componentChangerId, GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER_PED_ID(), componentChangerId), 0, 2); componentChangerdrawableId = GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER_PED_ID(), componentChangerId); }
		else{ SET_PED_COMPONENT_VARIATION(PLAYER_PED_ID(), componentChangerId, componentChangerdrawableId - 1, 0, 2); componentChangerdrawableId = componentChangerdrawableId - 1; }
		componentChangerTextureId = GET_PED_TEXTURE_VARIATION(PLAYER_PED_ID(), componentChangerId);
	}
	if (TextureP)
	{
		if (componentChangerTextureId == GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(PLAYER_PED_ID(), componentChangerId, componentChangerdrawableId)){ SET_PED_COMPONENT_VARIATION(PLAYER_PED_ID(), componentChangerId, componentChangerdrawableId, 0, 2); componentChangerTextureId = 0; }
		else{ SET_PED_COMPONENT_VARIATION(PLAYER_PED_ID(), componentChangerId, componentChangerdrawableId, componentChangerTextureId + 1, 2); componentChangerTextureId = componentChangerTextureId + 1; }
	}
	if (TextureM)
	{
		if (componentChangerTextureId == 0){ SET_PED_COMPONENT_VARIATION(PLAYER_PED_ID(), componentChangerId, componentChangerdrawableId, 0, 2); componentChangerTextureId = GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(PLAYER_PED_ID(), componentChangerId, componentChangerdrawableId); }
		else{ SET_PED_COMPONENT_VARIATION(PLAYER_PED_ID(), componentChangerId, componentChangerdrawableId, componentChangerTextureId - 1, 2); componentChangerTextureId = componentChangerTextureId - 1; }
	}
}
void ComponentPropChanger()
{
	bool VariationP = 0, VariationM = 0, TextureP = 0, TextureM = 0;

	AddTitle(componentChangerCompmentName);
	AddNumber2("Variation", componentChangerdrawableId, 0, null, VariationP, VariationM);
	AddNumber2("Texture", componentChangerTextureId, 0, null, TextureP, TextureM);

	if (VariationP)
	{
		if (componentChangerdrawableId == GET_NUMBER_OF_PED_PROP_DRAWABLE_VARIATIONS(PLAYER_PED_ID(), componentChangerId)){ SET_PED_PROP_INDEX(PLAYER_PED_ID(), componentChangerId, 0, 0, 1); componentChangerdrawableId = 0; }
		else{ SET_PED_PROP_INDEX(PLAYER_PED_ID(), componentChangerId, componentChangerdrawableId + 1, 0, 1); componentChangerdrawableId = componentChangerdrawableId + 1; }
		componentChangerTextureId = GET_PED_PROP_TEXTURE_INDEX(PLAYER_PED_ID(), componentChangerId);
	}
	if (VariationM)
	{
		if (componentChangerdrawableId == 0){ SET_PED_PROP_INDEX(PLAYER_PED_ID(), componentChangerId, GET_NUMBER_OF_PED_PROP_DRAWABLE_VARIATIONS(PLAYER_PED_ID(), componentChangerId), 0, 1); componentChangerdrawableId = GET_NUMBER_OF_PED_PROP_DRAWABLE_VARIATIONS(PLAYER_PED_ID(), componentChangerId); }
		else{ SET_PED_PROP_INDEX(PLAYER_PED_ID(), componentChangerId, componentChangerdrawableId - 1, 0, 2); componentChangerdrawableId = componentChangerdrawableId - 1; }
		componentChangerTextureId = GET_PED_PROP_TEXTURE_INDEX(PLAYER_PED_ID(), componentChangerId);
	}
	if (TextureP)
	{
		if (componentChangerTextureId == GET_NUMBER_OF_PED_PROP_TEXTURE_VARIATIONS(PLAYER_PED_ID(), componentChangerId, componentChangerdrawableId)){ SET_PED_PROP_INDEX(PLAYER_PED_ID(), componentChangerId, componentChangerdrawableId, 0, 1); componentChangerTextureId = 0; }
		else{ SET_PED_PROP_INDEX(PLAYER_PED_ID(), componentChangerId, componentChangerdrawableId, componentChangerTextureId + 1, 1); componentChangerTextureId = componentChangerTextureId + 1; }
	}
	if (TextureM)
	{
		if (componentChangerTextureId == 0){ SET_PED_PROP_INDEX(PLAYER_PED_ID(), componentChangerId, componentChangerdrawableId, 0, 1); componentChangerTextureId = GET_NUMBER_OF_PED_PROP_TEXTURE_VARIATIONS(PLAYER_PED_ID(), componentChangerId, componentChangerdrawableId); }
		else{ SET_PED_PROP_INDEX(PLAYER_PED_ID(), componentChangerId, componentChangerdrawableId, componentChangerTextureId - 1, 1); componentChangerTextureId = componentChangerTextureId - 1; }
	}
}
void ComponentSelector()
{
	bool SetDefault = 0, SetRandom = 0;
	AddTitle("Component changer");
	AddOption("Default", SetDefault);
	AddOption("Random", SetRandom);
	AddComponentSub("Face", 0);
	AddComponentSub("Beard", 1);
	AddComponentSub("Haircut", 2);
	AddComponentSub("Shirt", 3);
	AddComponentSub("Pants", 4);
	AddComponentSub("Hands / Gloves", 5);
	AddComponentSub("Shoes", 6);
	AddComponentSub("Eyes", 7);
	AddComponentSub("Accessories", 8);
	AddComponentSub("Mission Items/Tasks", 9);
	AddComponentSub("Decals", 10);
	AddComponentSub("Collars and Inner Shirts", 11);
	AddCompomentPropSub("Hat", 0);
	AddCompomentPropSub("Glasses", 1);
	if (SetDefault) SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER_PED_ID());
	if (SetRandom) SET_PED_RANDOM_COMPONENT_VARIATION(PLAYER_PED_ID(), true);
}
void AddWeather(char* text, char* weatherType)
{
	bool setWeather = 0;
	AddOption(text, setWeather);
	if (setWeather) _SET_WEATHER_TYPE_OVER_TIME(weatherType, 4.0);
}
void WeatherMenu()
{
	bool SP = 0, SM = 0, MP = 0, MM = 0, HP = 0, HM = 0, SnowON = 0, SnowOFF = 0;
	AddTitle("Weather");
	AddWeather("Clear", "clear");
	AddWeather("Extra Sunny", "extrasunny");
	AddWeather("Cloudy", "clouds");
	AddWeather("Overcast", "overcast");
	AddWeather("Raining", "rain");
	AddWeather("Clearing", "clearing");
	AddWeather("Thunder", "thunder");
	AddWeather("Smog", "smog");
	AddWeather("Foggy", "foggy");
	AddWeather("X-Mas", "xmas");
	AddWeather("Snow Light", "snowlight");
	AddWeather("Blizzard", "blizzard");
	AddWeather("Halloween", "halloween");
	AddToggle("Snow", SnowCheck, SnowON, SnowOFF);
	AddNumber("Minutes", GET_CLOCK_MINUTES(), 0, null, MP, MM);
	AddNumber2("Hours", GET_CLOCK_HOURS(), 0, null, HP, HM);
	//if (SP) SET_CLOCK_TIME(GET_CLOCK_HOURS(), GET_CLOCK_MINUTES(), GET_CLOCK_SECONDS() + 1);
	//if (SM) SET_CLOCK_TIME(GET_CLOCK_HOURS(), GET_CLOCK_MINUTES(), GET_CLOCK_SECONDS() - 1);
	if (MP){ if (GET_CLOCK_MINUTES() == 60) SET_CLOCK_TIME(GET_CLOCK_HOURS(), 0, GET_CLOCK_SECONDS()); else SET_CLOCK_TIME(GET_CLOCK_HOURS(), GET_CLOCK_MINUTES() + 1, GET_CLOCK_SECONDS()); }
	if (MM){ if (GET_CLOCK_MINUTES() == 0) SET_CLOCK_TIME(GET_CLOCK_HOURS(), 60, GET_CLOCK_SECONDS()); else SET_CLOCK_TIME(GET_CLOCK_HOURS(), GET_CLOCK_MINUTES() - 1, GET_CLOCK_SECONDS()); }
	if (HP){ if (GET_CLOCK_HOURS() == 24) SET_CLOCK_TIME(0, GET_CLOCK_MINUTES(), GET_CLOCK_SECONDS()); else SET_CLOCK_TIME(GET_CLOCK_HOURS() + 1, GET_CLOCK_MINUTES(), GET_CLOCK_SECONDS()); }
	if (HM){ if (GET_CLOCK_HOURS() == 0) SET_CLOCK_TIME(24, GET_CLOCK_MINUTES(), GET_CLOCK_SECONDS()); else  SET_CLOCK_TIME(GET_CLOCK_HOURS() - 1, GET_CLOCK_MINUTES(), GET_CLOCK_SECONDS()); }
	if (SnowON) EnableSnow(true);
	if (SnowOFF) EnableSnow(false);
}
void Player()

{
	bool  godmodeON = 0, godmodeOFF = 0, fillhealth = 0, wantedlevel = 0, WantedP = 0, WantedM = 0, NeverWantedON = 0, NeverWantedOFF = 0, visible = 0, invisible = 0;

	AddTitle("Player");
	AddOption("Change Model", null, nullFunc, SUB::MODELCHANGER);
	AddOption("Animations", null, nullFunc, SUB::ANIMATIONS);
	AddOption("Scenarios", null, nullFunc, SUB::SCENARIOS);
	AddOption("Component changer", null, nullFunc, SUB::COMPONENTSELECTOR);
	AddToggle("Invincible", godmode_check, godmodeON, godmodeOFF);
	AddToggle("Visible", visibleCheck, visible, invisible);
	AddToggle("Super Run", superruncheck);
	AddToggle("Super Jump", superjump_check);
	AddToggle("Never Wanted", neverwanted_check, NeverWantedON, NeverWantedOFF);
	AddToggle("Unlimited Special Ability", UnlimitedAbility_check);
	//AddToggle("Hancock mode", super_check);
	//AddToggle("Superman Manual", SuperManualCheck);
	AddNumber2("Wanted Level", GET_PLAYER_WANTED_LEVEL(PLAYER_ID()), 0, null, WantedP, WantedM);
	AddOption("Clear wanted level", wantedlevel);

	if (godmodeON){
		SET_PLAYER_INVINCIBLE(PLAYER_ID(), true);
		PrintStringBottomCentre(AddStrings("Invincible  ", "~g~ON"));
		return;
	}

	if (godmodeOFF){
		SET_PLAYER_INVINCIBLE(PLAYER_ID(), false);
		PrintStringBottomCentre(AddStrings("Invincible  ", "~r~OFF"));
		return;
	}

	if (NeverWantedON) { CLEAR_PLAYER_WANTED_LEVEL(PLAYER_ID()); SET_MAX_WANTED_LEVEL(0); PrintStringBottomCentre("Never Wanted  ~g~ON"); }
	if (NeverWantedOFF) { SET_MAX_WANTED_LEVEL(5); PrintStringBottomCentre("Never Wanted  ~r~OFF"); }

	if (wantedlevel){
		CLEAR_PLAYER_WANTED_LEVEL(PLAYER_ID());
		return;
	}

	if (WantedP){
		if (GET_PLAYER_WANTED_LEVEL(PLAYER_ID()) == 5) return;
		else { SET_PLAYER_WANTED_LEVEL(PLAYER_ID(), GET_PLAYER_WANTED_LEVEL(PLAYER_ID()) + 1, false); SET_PLAYER_WANTED_LEVEL_NOW(PLAYER_ID(), false); }
	}

	if (WantedM){
		if (GET_PLAYER_WANTED_LEVEL(PLAYER_ID()) == 0) return;
		else { SET_PLAYER_WANTED_LEVEL(PLAYER_ID(), GET_PLAYER_WANTED_LEVEL(PLAYER_ID()) - 1, false); SET_PLAYER_WANTED_LEVEL_NOW(PLAYER_ID(), false); }
	}

//	if (super_run){
//		superrun();
//		return;
//	}

	if (visible){ SET_ENTITY_VISIBLE(PLAYER_PED_ID(), 1); PrintStringBottomCentre("Visible"); }
	if (invisible){ SET_ENTITY_VISIBLE(PLAYER_PED_ID(), 0); PrintStringBottomCentre("Invisible"); }



}
}




void menu::loops()
{ 
	/*	Make calls to functions that you want looped over here, e.g. ambient lights, whale guns, explosions, checks, flying deers, etc.
		Can also be used for (bool) options that are to be executed from many parts of the script. */

	myVeh = GET_VEHICLE_PED_IS_IN(PLAYER_PED_ID(), 0); // Store current vehicle

	if (loop_massacre_mode) set_massacre_mode(); // Massacre mode

	if (loop_RainbowBoxes && GET_GAME_TIMER() >= livetimer)
	{	titlebox.R = RandomRGB(); titlebox.G = RandomRGB(); titlebox.B = RandomRGB();
		BG.R = RandomRGB(); BG.G = RandomRGB(); BG.B = RandomRGB();
		selectedtext.R = RandomRGB(); selectedtext.G = RandomRGB(); selectedtext.B = RandomRGB();
	}


	if (loop_gravity_gun) set_gravity_gun();

	if (loop_gta2cam) set_gta2_cam_rot();

	if (super_check) super_loop();

	if (activenos) nosloop();

	if (boost_check) boostloop();

	if (superruncheck) superrun_loop();

	if (sbrake_check) sbrakeloop();

	if (carjump_check) CarJumpLoop();

	if (vehWeaponsCheck) VehWeaponsLoop();

	if (radarphone_check) RadarPhoneLoop();

	if (fixcar_check) FixCarLoop();

	if (UnlimitedAbility_check) UnlimitedAbilityLoop();

	if (superjump_check) SuperJumpLoop();

	if (Test1_check) Test1();

	if (driveunderwater_check) DriveUnderWaterLoop();

	if (fwgun_check) FireworkGun();

	if (cash_check) CashDropLoop();

	if (godmode_check) GodmodeLoop();

	if (VehGodmodeCheck) VehGodmodeLoop();

	if (brawler_check) BrawlerLoop();

	if (TrainSpeedControlCheck) TrainSpeedControl();

	if (TorqueMultiCheck) TorqueMultiplier();

	if (Drive_on_water) DriveOnWater();

	if (customBulletsCheck) CustomBullets_();

	if (DriveTrainCheck) DriveTrains();

	if (RainbowCarCheck) RainBowCar();

	if (SuperManualCheck) SupermanManual();

	if (speedometerCheck) SpeedoMeter();

	if (FreeCam) FreeCamLoop();

	if (!visibleCheck) SET_ENTITY_VISIBLE(PLAYER_PED_ID(), 0);

	if (LoopNotification) NotificationLoop();

	if (SwitchingSubmenu) SetSubNewLoop();

	if (draw_fps) DrawFps();

	if (ModJustLoadedCheck) ModJustLoaded();

	if (RainbowNeonCheck) RainbowNeon();

	if (DebugMode) DrawDebugConsole();

	if (Draw_Coords) DrawCoords();

	if (ColorAnimationRunning) VehColorAnimation();

	if (TSlowStop) TrainSlowStop();

	if (missionEntityLoop) MissionEntityLoop();

	if (CrashAvoid) CrashAvoidMain();

}

void menu::submenu_switch()
{ // Make calls to submenus over here.

	switch (currentsub)
	{
	case SUB::MAINMENU:					sub::MainMenu(); break;
	case SUB::SETTINGS:					sub::Settings(); break;
	case SUB::SETTINGS_COLOURS:			sub::SettingsColours(); break;
	case SUB::SETTINGS_COLOURS2:		sub::SettingsColours2(); break;
	case SUB::SETTINGS_FONTS:			sub::SettingsFonts(); break;
	case SUB::SETTINGS_FONTS2:			sub::SettingsFonts2(); break;
	case SUB::SAMPLE:					sub::SampleSub(); break;
	case SUB::YOURSUB:					sub::YourSub(); break;
	case SUB::ONLINEPLAYERS:            sub::OnlinePlayers(); break;
	case SUB::PLAYER:                   sub::Player(); break;
	case SUB::MISC:                     sub::Misc(); break;
	case SUB::VEHICLE1:                 sub::Vehicle1(); break;
	case SUB::RECOVERY:                 sub::Recovery(); break;
	case SUB::TELEPORT:                 sub::Teleport(); break;
	case SUB::INSIDEBUILDINGS:          sub::InsideBuildings(); break;
	case SUB::CARCOLORS:                sub::CarColors(); break;
	case SUB::PRIMARY:                  sub::ColorCatMenu(ColorTypes::PRIMARY); break;
	case SUB::SECONDARY:                sub::ColorCatMenu(ColorTypes::SECONDARY); break;
	case SUB::ONLINEPLAYER:             sub::OnlinePlayer(); break;
	case SUB::MODSHOP:                  sub::ModShop(); break;
	case SUB::ENGINE:                   sub::Engine(); break;
	case SUB::TRANSMISSION:             sub::Transmission(); break;
	case SUB::BRAKES:                   sub::Brakes(); break;
	case SUB::SUSPENSION:               sub::Suspension(); break;
	case SUB::EXHAUST:                  sub::Exhaust(); break;
	case SUB::TURBO:                    sub::Turbo(); break;
	case SUB::FRONTB_MENU:              sub::FrontB_Menu(); break;
	case SUB::REARB_MENU:               sub::RearB_Menu(); break;
	case SUB::SIDE_SKIRTS:              sub::Side_skirts(); break;
	case SUB::HOODS:                    sub::Hoods(); break;
	case SUB::SPOILER:                  sub::Spoiler(); break;
	case SUB::ARMOUR:                   sub::Armour(); break;
	case SUB::VEHICLESPAWNER:           sub::VehicleSpawner(); break;
	case SUB::PEGASUSP:                 sub::PegasusP(); break;
	case SUB::ALLPLAYERS:               sub::allplayers(); break;
	case SUB::IPLLOADER:                sub::iplLoader(); break;
	case SUB::NORTHYANKTON:             sub::NorthYankton(); break;
	case SUB::MODELCHANGER:             sub::ModelChanger(); break;
	case SUB::IGG:                      sub::ILLGOTTENGAINS_vehicles(); break;
	case SUB::YACHT:                    sub::Yacht(); break;
	case SUB::HYACT:                    sub::HYacht(); break;
	case SUB::HCARRIER:                 sub::HCarrier(); break;
	case SUB::DHOSPITAL:                sub::Dhosptal(); break;
	case SUB::JSTORE:                   sub::JStore(); break;
	case SUB::MORGUE:                   sub::Morgue(); break;
	case SUB::CSHIP:                    sub::CShip(); break;
	case SUB::ONRANCH:                  sub::ONRanch(); break;
	case SUB::BONRANCH:                 sub::BONRanch(); break;
	case SUB::LLOBBY:                   sub::LLobby(); break;
	case SUB::FIBLOBBY:                 sub::FIB_lobby(); break;
	case SUB::TCRASH:                   sub::TCrash(); break;
	case SUB::BSHOUSE:                  sub::B_S_House(); break;
	case SUB::PCRASH:                   sub::PCrash(); break;
	case SUB::CBELL:                    sub::CBell(); break;
	case SUB::UFO:                      sub::UFO(); break;
	case SUB::OBJECTSPAWNER:            sub::ObjectSpawner(); break;
	case SUB::PEDSPAWNER:               sub::PedSpawnMenu(); break;
	case SUB::WEAPONS:                  sub::Weapons(); break;
	case SUB::NEON:                     sub::Neon_menu(); break;
	case SUB::NEONL:                    sub::Neon_layout(); break;
	case SUB::NEONC:                    sub::Neon_color(); break;
	case SUB::CUSTOMPRIMARY:            sub::CustomColorMenu(ColorTypes::PRIMARY); break;
	case SUB::CUSTOMSECONDARY:          sub::CustomColorMenu(ColorTypes::SECONDARY); break;
	case SUB::VSSUPER:                  sub::VSSuper(); break;
	case SUB::ONLINEVEHICLE:            sub::OnlineVehicle(); break;
	case SUB::PEDOPTIONS:               sub::PedOptions(); break;
	case SUB::PED:                      sub::Ped(); break;
	case SUB::PEDSPAWNERSETTINGS:       sub::PedSpawnerSettings(); break;
	case SUB::MULTIPLIERS:              sub::Multipliers(); break;
	case SUB::CUSTOMBULLETS:            sub::CustomBullets(); break;
	case SUB::ROOF:                     sub::Roof(); break;
	case SUB::BETA:                     sub::Beta(); break;
	case SUB::VSSPORTS:                 sub::VSSports(); break;
	case SUB::VSSPORTSC:                sub::SportsClassic(); break;
	case SUB::MUSCLE:                   sub::Muscle(); break;
	case SUB::SEDANS:                   sub::Sedans(); break;
	case SUB::COUPES:                   sub::Coupes(); break;
	case SUB::COMPACT:                  sub::Compact(); break;
	case SUB::SUVANDTRUCK:              sub::SUVandTruck(); break;
	case SUB::OFFROAD:                  sub::OffRoad(); break;
	case SUB::SAVELOADVEHICLE:          sub::SaveLoadVeh(); break;
	case SUB::SAVEDVEHICLES:            sub::SavedVehiclesOptions(); break;
	case SUB::DEVMENU:                  sub::DevMenu(); break;
	case SUB::GRILLE:                   sub::Grille(); break;
	case SUB::HORN:                     sub::Horn(); break;
	case SUB::WHEELS:                   sub::Wheels(); break;
	case SUB::WHEELTYPE:                sub::WheelType(); break;
	case SUB::SELECTWHEEL:              sub::SelectWheel(); break;
	case SUB::ANIMATIONS:               sub::Animations(); break;
	case SUB::ONLINEBLAMEPLAYER:        sub::OnlineBlamePlayer(); break;
	case SUB::SCENARIOS:                sub::Scenarios(); break;
	case SUB::OBJECTOPTIONS:            sub::ObjectOptions(); break;
	case SUB::OBJECT:                   sub::Object(); break;
	case SUB::PEDSPAWNERXYZ:            sub::PedSpawnerSetCoords(); break;
	case SUB::SPEEDOMETERMENU:          sub::SpeedoMeterMenu(); break;
	case SUB::COMPONENTSELECTOR:        sub::ComponentSelector(); break;
	case SUB::COMPONENTCHANGER:         sub::ComponentChanger(); break;
	case SUB::VSVANS:                   sub::Vans(); break;
	case SUB::VSEMERGENCY:              sub::Emergency(); break;
	case SUB::VSSERVICE:                sub::Service(); break;
	case SUB::VSMILITARY:               sub::Military(); break;
	case SUB::VSMOTORCYCLES:            sub::Motorcycles(); break;
	case SUB::VSBICYCLES:               sub::Bicycles(); break;
	case SUB::VSCOMMERCIAL:             sub::Commercial(); break;
	case SUB::VSHELICOPTERS:            sub::Helicopters(); break;
	case SUB::VSPLANES:                 sub::Planes(); break;
	case SUB::VSBOATS:                  sub::Boats(); break;
	case SUB::VSTRAILERS:               sub::Trailers(); break;
	case SUB::VSSETTINGS:               sub::VSSettings(); break;
	case SUB::ADDCUSTOMOBJECT:          sub::AddCustomObject(); break;
	case SUB::PEDSPAWNERWEAPONSELECTION:sub::PedSpawnerWeaponSelection(); break;
	case SUB::VEHWEAPONSMENU:           sub::VehWeaponsMenu(); break;
	case SUB::LOWRIDERDLC:              sub::LowrideDLC(); break;
	case SUB::BAHAMAMAMAS:              sub::BahamaMamas(); break;
	case SUB::CUSTOMVEHMOD:             sub::CustomVehMod(); break;
	case SUB::BENNYS:                   sub::Bennys(); break;
	case SUB::BENNYSMODS:               sub::BennysMods(); break;
	case SUB::VEHINTERIOR:              sub::VehInterior(); break;
	case SUB::VEHINTERIORCOLOR:         sub::VehInteriorColor(); break;
	case SUB::VEHDASHBOARDCOLOR:        sub::VehDashBoardColor(); break;
	case SUB::MODLABELS:                sub::ModLabels(); break;
	case SUB::VEHTRIM:                  sub::VehTrim(); break;
	case SUB::PRESETCUSTOMCOLORS:       sub::PresetCustomColorMenu(ColorTypes::PRIMARY); break;
	case SUB::PRESETCUSTOMSECONDARY:    sub::PresetCustomColorMenu(ColorTypes::SECONDARY); break;
	case SUB::LIGHTS:                   sub::LightsMenu(); break;
	case SUB::HEADLIGHTS:               sub::HeadLightsMenu(); break;
	case SUB::NEOCUSTOMRGB:             sub::NeonColorCustomRGB(); break;
	case SUB::PTFXTEST:                 sub::PTFXTestMenu(); break;
	case SUB::COMPONENTCHANGERPROP:     sub::ComponentPropChanger(); break;
	case SUB::WEATHER:                  sub::WeatherMenu(); break;
	case SUB::DOORMENU:                 sub::DoorMenu(); break;
	case SUB::SAVEDVEHEDITOR:           sub::SavedVehEditor(); break;
	case SUB::CUSTOMVEHCATEGORY:        sub::CustomVehCategory(); break;
	case SUB::ADDTOCUSTOMVEHICLES:      sub::AddToCustomVehicles(); break;
	case SUB::DELTEFROMCUSTOMVEHICLES:  sub::DeleteFromCustomVehicles(); break;
	case SUB::PRIMARYCOLORCLASSIC:		sub::ClassicColorMenu(ColorTypes::PRIMARY); break;
	case SUB::PRIMARYCOLORMATTE:		sub::MatteColorMenu(ColorTypes::PRIMARY); break;
	case SUB::PRIMARYCOLORMETALIC:		sub::MettalicColorMenu(ColorTypes::PRIMARY); break;
	case SUB::SECONDARYCOLORCLASSIC:	sub::ClassicColorMenu(ColorTypes::SECONDARY); break;
	case SUB::SECONDARYCOLORMATTE:		sub::MatteColorMenu(ColorTypes::SECONDARY); break;
	case SUB::SECONDARYCOLORMETALIC:	sub::MettalicColorMenu(ColorTypes::SECONDARY); break;

	}
}


void menu::sub_handler()
{
	if (currentsub == SUB::CLOSED){
		while_closed();
	}

	else{
		submenu_switch();
		if (SetSub_delayed != NULL)
		{
			SetSub_new(SetSub_delayed);
			SetSub_delayed = NULL;
		}

		while_opened();

		if (GET_GAME_TIMER() >= livetimer) livetimer = GET_GAME_TIMER() + 1800; // 1.8s delay for rainbow related loops
	}
}
void main()
{
	srand(GetTickCount());
	while (true)
	{
		WAIT(0);
		menu::base();
		menu::loops();
		menu::sub_handler();
	}
}

 
