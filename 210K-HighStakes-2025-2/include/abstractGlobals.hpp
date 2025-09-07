#pragma once

// 3rd party libraries
#include "lemlib/api.hpp"
#include "gif-pros/gifclass.hpp"
#include "robodash/api.h"
#include "liblvgl/lvgl.h"

extern rd::Console console;
extern rd_view_t *gifview;
extern rd_view_t *allianceview;
extern rd::Selector gui_selector;
void rdconfig_init();

extern std::string alliance;
extern std::string field_status;
extern bool intakeLock;

extern bool colourSortToggle;
extern bool antiJamToggle;

extern void competitionTelemtryRefresh();
extern bool isResetting;
extern int wallstakeStates[];

/* Functions */
// DT
void arcadeDrive();

void refreshIntake();
void refreshClamp();
void refreshDoinker();
void refreshWallstakes();
void resetWallstakes();

void liftControl(double target);

void initializeColourSort();
void driverSkillsMacro();

/* Autons */
void sawp();
void half_sawp();
void ring_rush();
void skills();