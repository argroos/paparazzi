/* This file has been generated by gen_flight_plan from /home/argroos/paparazzi/conf/flight_plans/FlyHigh/Wolfshoehe_Glide_Test_2023-09-15.xml */
/* Version v6.4.0_stable */
/* Please DO NOT EDIT */

#ifndef FLIGHT_PLAN_H
#define FLIGHT_PLAN_H

#include "std.h"
#include "generated/modules.h"
#include "modules/core/abi.h"
#include "autopilot.h"


#include "modules/datalink/datalink.h"

#define FLIGHT_PLAN_NAME "Wolfshoehe_Glide_Test"
#define NAV_DEFAULT_ALT 436 /* nominal altitude of the flight plan */
#define NAV_UTM_EAST0 641794
#define NAV_UTM_NORTH0 5474653
#define NAV_UTM_ZONE0 32
#define NAV_LAT0 494080290 /* 1e7deg */
#define NAV_LON0 109546770 /* 1e7deg */
#define NAV_ALT0 356000 /* mm above msl */
#define NAV_MSL0 48350 /* mm, EGM96 geoid-height (msl) over ellipsoid */
#define QFU 0.0
#define WP_dummy 0
#define WP_HOME 1
#define WP_Profile 2
#define WP_WP01 3
#define WP_WP02 4
#define WP_WP03 5
#define WP_WP04 6
#define WP_WP05 7
#define WP_WP06 8
#define WP_WP07 9
#define WP_WP08 10
#define WP_WP09 11
#define WAYPOINTS_UTM { \
 {0.0, 0.0, 436},\
 {0.0, 0.0, 436},\
 {2.8, -28.3, 436},\
 {26.0, -151.9, 446},\
 {-36.2, -162.2, 446},\
 {-65.0, 41.4, 466},\
 {-39.1, 45.7, 466},\
 {-5.8, -158.2, 446},\
 {50.2, -148.3, 446},\
 {20.5, 50.2, 476},\
 {-7.6, 47.8, 476},\
 {13.5, -78.4, 436},\
};
#define WAYPOINTS_ENU { \
 {-0.00, -0.00, 80.00}, /* ENU in meters  */ \
 {-0.00, -0.00, 80.00}, /* ENU in meters  */ \
 {2.11, -28.36, 80.00}, /* ENU in meters  */ \
 {22.06, -152.60, 90.00}, /* ENU in meters  */ \
 {-40.43, -161.27, 90.00}, /* ENU in meters  */ \
 {-63.94, 43.04, 110.00}, /* ENU in meters  */ \
 {-37.96, 46.72, 110.00}, /* ENU in meters  */ \
 {-9.94, -158.05, 90.00}, /* ENU in meters  */ \
 {46.38, -149.59, 90.00}, /* ENU in meters  */ \
 {21.77, 49.71, 120.00}, /* ENU in meters  */ \
 {-6.38, 47.94, 120.00}, /* ENU in meters  */ \
 {11.47, -78.75, 80.00}, /* ENU in meters  */ \
};
#define WAYPOINTS_LLA { \
 {.lat=494080289, .lon=109546769, .alt=436000}, /* 1e7deg, 1e7deg, mm (above NAV_MSL0, local msl=48.35m) */ \
 {.lat=494080289, .lon=109546769, .alt=436000}, /* 1e7deg, 1e7deg, mm (above NAV_MSL0, local msl=48.35m) */ \
 {.lat=494077740, .lon=109547060, .alt=436000}, /* 1e7deg, 1e7deg, mm (above NAV_MSL0, local msl=48.35m) */ \
 {.lat=494066570, .lon=109549809, .alt=446000}, /* 1e7deg, 1e7deg, mm (above NAV_MSL0, local msl=48.35m) */ \
 {.lat=494065790, .lon=109541199, .alt=446000}, /* 1e7deg, 1e7deg, mm (above NAV_MSL0, local msl=48.35m) */ \
 {.lat=494084159, .lon=109537959, .alt=466000}, /* 1e7deg, 1e7deg, mm (above NAV_MSL0, local msl=48.35m) */ \
 {.lat=494084490, .lon=109541539, .alt=466000}, /* 1e7deg, 1e7deg, mm (above NAV_MSL0, local msl=48.35m) */ \
 {.lat=494066080, .lon=109545400, .alt=446000}, /* 1e7deg, 1e7deg, mm (above NAV_MSL0, local msl=48.35m) */ \
 {.lat=494066840, .lon=109553160, .alt=446000}, /* 1e7deg, 1e7deg, mm (above NAV_MSL0, local msl=48.35m) */ \
 {.lat=494084759, .lon=109549769, .alt=476000}, /* 1e7deg, 1e7deg, mm (above NAV_MSL0, local msl=48.35m) */ \
 {.lat=494084600, .lon=109545890, .alt=476000}, /* 1e7deg, 1e7deg, mm (above NAV_MSL0, local msl=48.35m) */ \
 {.lat=494073209, .lon=109548349, .alt=436000}, /* 1e7deg, 1e7deg, mm (above NAV_MSL0, local msl=48.35m) */ \
};
#define WAYPOINTS_LLA_WGS84 { \
 {.lat=494080289, .lon=109546769, .alt=484350}, /* 1e7deg, 1e7deg, mm (above WGS84 ref ellipsoid) */ \
 {.lat=494080289, .lon=109546769, .alt=484350}, /* 1e7deg, 1e7deg, mm (above WGS84 ref ellipsoid) */ \
 {.lat=494077740, .lon=109547060, .alt=484350}, /* 1e7deg, 1e7deg, mm (above WGS84 ref ellipsoid) */ \
 {.lat=494066570, .lon=109549809, .alt=494350}, /* 1e7deg, 1e7deg, mm (above WGS84 ref ellipsoid) */ \
 {.lat=494065790, .lon=109541199, .alt=494350}, /* 1e7deg, 1e7deg, mm (above WGS84 ref ellipsoid) */ \
 {.lat=494084159, .lon=109537959, .alt=514350}, /* 1e7deg, 1e7deg, mm (above WGS84 ref ellipsoid) */ \
 {.lat=494084490, .lon=109541539, .alt=514350}, /* 1e7deg, 1e7deg, mm (above WGS84 ref ellipsoid) */ \
 {.lat=494066080, .lon=109545400, .alt=494350}, /* 1e7deg, 1e7deg, mm (above WGS84 ref ellipsoid) */ \
 {.lat=494066840, .lon=109553160, .alt=494350}, /* 1e7deg, 1e7deg, mm (above WGS84 ref ellipsoid) */ \
 {.lat=494084759, .lon=109549769, .alt=524350}, /* 1e7deg, 1e7deg, mm (above WGS84 ref ellipsoid) */ \
 {.lat=494084600, .lon=109545890, .alt=524350}, /* 1e7deg, 1e7deg, mm (above WGS84 ref ellipsoid) */ \
 {.lat=494073209, .lon=109548349, .alt=484350}, /* 1e7deg, 1e7deg, mm (above WGS84 ref ellipsoid) */ \
};
#define WAYPOINTS_GLOBAL { \
 FALSE, \
 TRUE, \
 TRUE, \
 TRUE, \
 TRUE, \
 TRUE, \
 TRUE, \
 TRUE, \
 TRUE, \
 TRUE, \
 TRUE, \
 TRUE, \
};
#define NB_WAYPOINT 12
#define FP_BLOCKS { \
 "Wait GPS" , \
 "Geo init" , \
 "Waiting for Remote Control" , \
 "Holding point" , \
 "Takeoff" , \
 "Climb" , \
 "Circle" , \
 "Survey" , \
 "Down" , \
 "Up" , \
 "Standby" , \
 "HOME" , \
}
#define NB_BLOCK 12
#define GROUND_ALT 356.
#define GROUND_ALT_CM 35600
#define SECURITY_HEIGHT 50.
#define SECURITY_ALT 406.
#define HOME_MODE_HEIGHT 50.
#define MAX_DIST_FROM_HOME 400.


#ifndef FBW


#endif

#ifdef NAV_C


static inline void auto_nav_init(void) {
}

static inline void auto_nav(void) {
  if ((nav_block != 10) && (10.500000>PowerVoltage())) { GotoBlock(10); return; }
  switch (nav_block) {
    Block(0) // Wait GPS
    switch(nav_stage) {
      Stage(0)
        autopilot.kill_throttle = 1;
        NextStage();
      Label(while_1)
      Stage(1)
        if (! (!(GpsFixValid()))) Goto(endwhile_2) else NextStageAndBreak();
        Stage(2)
          Goto(while_1)
        Label(endwhile_2)
      /* Falls through. */
      default:
      Stage(3)
        NextBlock();
        break;
    }
    break;

    Block(1) // Geo init
    switch(nav_stage) {
      Label(while_3)
      Stage(0)
        if (! (LessThan(NavBlockTime(),10))) Goto(endwhile_4) else NextStageAndBreak();
        Stage(1)
          Goto(while_3)
        Label(endwhile_4)
      /* Falls through. */
      default:
      Stage(2)
        NextBlock();
        break;
    }
    break;

    Block(2) // Waiting for Remote Control
    switch(nav_stage) {
      Label(while_5)
      Stage(0)
        if (! (RCLost())) Goto(endwhile_6) else NextStageAndBreak();
        Stage(1)
          Goto(while_5)
        Label(endwhile_6)
      /* Falls through. */
      default:
      Stage(2)
        NextBlock();
        break;
    }
    break;

    Block(3) // Holding point
    switch(nav_stage) {
      Stage(0)
        autopilot.kill_throttle = 1;
        NextStage();
      Stage(1)
        NavAttitude(RadOfDeg(0));
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalThrottleMode(9600*(0));
        break;
      /* Falls through. */
      default:
      Stage(2)
        NextBlock();
        break;
    }
    break;

    Block(4) // Takeoff
    switch(nav_stage) {
      Stage(0)
        autopilot.kill_throttle = 0;
        NextStage();
      Stage(1)
        autopilot.flight_time = 0;
        NextStage();
      Stage(2)
        autopilot.kill_throttle = 0;
        NextStage();
      /* Falls through. */
      default:
      Stage(3)
        NextBlock();
        break;
    }
    break;

    Block(5) // Climb
    switch(nav_stage) {
      Stage(0)
        NavVerticalAutoThrottleMode(RadOfDeg(30));
        NavVerticalThrottleMode(9600*(0.800000));
        NavCircleWaypoint(2, 60);
        if ((GetPosAlt()>(ground_alt+100))) {
          NextStageAndBreak()
        }
        break;
      Stage(1)
        GotoBlock(6);
        break;
      /* Falls through. */
      default:
      Stage(2)
        NextBlock();
        break;
    }
    break;

    Block(6) // Circle
    if ((nav_block != 8) && (GetPosAlt()>(GetAltRef()+120))) { GotoBlock(8); return; }
    switch(nav_stage) {
      Stage(0)
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalAltitudeMode((GetAltRef()+100), 0.);
        NavCircleWaypoint(2, 60);
        if ((stage_time>10)) {
          NextStageAndBreak()
        }
        break;
      Stage(1)
        GotoBlock(7);
        break;
      /* Falls through. */
      default:
      Stage(2)
        NextBlock();
        break;
    }
    break;

    Block(7) // Survey
    if ((nav_block != 9) && ((ground_alt+70)>GetPosAlt())) { GotoBlock(9); return; }
    switch(nav_stage) {
      Stage(0)
        if (NavApproaching(3,CARROT)) {
          NextStageAndBreakFrom(3);
        } else {
          NavGotoWaypoint(3);
          NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
          NavVerticalAltitudeMode(WaypointAlt(3), 0.);
        }
        break;
      Stage(1)
        if (NavApproachingFrom(4,3,1)) {
          NextStageAndBreakFrom(4);
        } else {
          NavSegment(3, 4);
          NavVerticalAutoPitchMode(9600*(0.600000));
          NavGlide(3, 4);
        }
        break;
      Stage(2)
        if (NavApproachingFrom(5,4,1)) {
          NextStageAndBreakFrom(5);
        } else {
          NavSegment(4, 5);
          NavVerticalAutoPitchMode(9600*(0.600000));
          NavGlide(4, 5);
        }
        break;
      Stage(3)
        if (NavApproachingFrom(6,5,1)) {
          NextStageAndBreakFrom(6);
        } else {
          NavSegment(5, 6);
          NavVerticalAutoPitchMode(9600*(0.600000));
          NavGlide(5, 6);
        }
        break;
      Stage(4)
        if (NavApproachingFrom(7,6,1)) {
          NextStageAndBreakFrom(7);
        } else {
          NavSegment(6, 7);
          NavVerticalAutoPitchMode(9600*(0.600000));
          NavGlide(6, 7);
        }
        break;
      Stage(5)
        if (NavApproachingFrom(8,7,1)) {
          NextStageAndBreakFrom(8);
        } else {
          NavSegment(7, 8);
          NavVerticalAutoPitchMode(9600*(0.600000));
          NavGlide(7, 8);
        }
        break;
      Stage(6)
        if (NavApproachingFrom(9,8,1)) {
          NextStageAndBreakFrom(9);
        } else {
          NavSegment(8, 9);
          NavVerticalAutoPitchMode(9600*(0.600000));
          NavGlide(8, 9);
        }
        break;
      Stage(7)
        if (NavApproachingFrom(10,9,1)) {
          NextStageAndBreakFrom(10);
        } else {
          NavSegment(9, 10);
          NavVerticalAutoPitchMode(9600*(0.600000));
          NavGlide(9, 10);
        }
        break;
      Stage(8)
        if (NavApproachingFrom(11,10,1)) {
          NextStageAndBreakFrom(11);
        } else {
          NavSegment(10, 11);
          NavVerticalAutoPitchMode(9600*(0.600000));
          NavGlide(10, 11);
        }
        break;
      Stage(9)
        GotoBlock(8);
        break;
      /* Falls through. */
      default:
      Stage(10)
        NextBlock();
        break;
    }
    break;

    Block(8) // Down
    switch(nav_stage) {
      Stage(0)
        NavVerticalAutoThrottleMode(RadOfDeg(-(5)));
        NavVerticalThrottleMode(9600*(0.400000));
        NavCircleWaypoint(2, 60);
        if (((ground_alt+50)>GetPosAlt())) {
          NextStageAndBreak()
        }
        break;
      Stage(1)
        GotoBlock(10);
        break;
      /* Falls through. */
      default:
      Stage(2)
        NextBlock();
        break;
    }
    break;

    Block(9) // Up
    switch(nav_stage) {
      Stage(0)
        NavVerticalAutoThrottleMode(RadOfDeg(30));
        NavVerticalThrottleMode(9600*(0.800000));
        NavCircleWaypoint(2, 60);
        if ((GetPosAlt()>(ground_alt+100))) {
          NextStageAndBreak()
        }
        break;
      Stage(1)
        Return(0);
        break;
      /* Falls through. */
      default:
      Stage(2)
        NextBlock();
        break;
    }
    break;

    Block(10) // Standby
    switch(nav_stage) {
      Stage(0)
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalAltitudeMode(WaypointAlt(2), 0.);
        NavCircleWaypoint(2, 60);
        break;
      /* Falls through. */
      default:
      Stage(1)
        NextBlock();
        break;
    }
    break;

    Block(11) // HOME
    switch(nav_stage) {
      Stage(0)
        nav_home();
        break;
      /* Falls through. */
      default:
      Stage(1)
        NextBlock();
        break;
    }
    break;

    default: break;
  }
}
#endif // NAV_C

#endif // FLIGHT_PLAN_H
