/* This file has been generated from /home/argroos/paparazzi/conf/modules/gps_ubx_ucenter.xml /home/argroos/paparazzi/conf/modules/ahrs_float_dcm.xml /home/argroos/paparazzi/conf/modules/gps_ublox.xml /home/argroos/paparazzi/conf/modules/stabilization_attitude_fw.xml /home/argroos/paparazzi/conf/modules/logger_sd_chibios.xml /home/argroos/paparazzi/conf/modules/imu_common.xml /home/argroos/paparazzi/conf/modules/guidance_basic_fw.xml /home/argroos/paparazzi/conf/modules/electrical.xml /home/argroos/paparazzi/conf/modules/gps.xml /home/argroos/paparazzi/conf/modules/nav_basic_fw.xml /home/argroos/paparazzi/conf/modules/power_switch.xml /home/argroos/paparazzi/conf/settings/fixedwing_basic.xml */
/* Version v6.4.0_stable */
/* Please DO NOT EDIT */

#ifndef SETTINGS_H
#define SETTINGS_H


#include "generated/periodic_telemetry.h"
#include "mcu.h"
#include "autopilot.h"
#include "firmwares/fixedwing/nav.h"
#include "boards/power_switch.h"
#include "modules/nav/nav_survey_rectangle.h"
#include "firmwares/fixedwing/nav.h"
#include "modules/gps/gps.h"
#include "modules/energy/electrical.h"
#include "guidance/guidance_v.h"
#include "modules/imu/imu.h"
#include "loggers/sdlog_chibios/usbStorage.h"
#include "stabilization/stabilization_attitude.h"
#include "modules/core/commands.h"
#include "gps/gps_ubx.h"
#include "modules/ahrs/ahrs.h"
#include "gps/gps_ubx_ucenter.h"
#include "generated/modules.h"

#define SETTINGS_NAMES { \
 { "telemetry_mode_Ap" }, \
 { "telemetry_mode_Fbw" }, \
 { "trisonica_trisonica_report_status" }, \
 { "gps_ublox_gps_ubx_periodic_check_status" }, \
 { "flight_recorder_flight_recorder_periodic_status" }, \
 { "gps_ubx_ucenter_gps_ubx_ucenter_periodic_status" }, \
 { "mag_lis3mdl_mag_lis3mdl_report_status" }, \
 { "mcu_reboot" }, \
 { "autopilot.mode" }, \
 { "autopilot.launch" }, \
 { "autopilot.kill_throttle" }, \
 { "flight_altitude" }, \
 { "nav_course" }, \
 { "nav_shift" }, \
 { "autopilot.flight_time" }, \
 { "nav_radius" }, \
 { "power_switch_status" }, \
 { "nav_radius" }, \
 { "nav_course" }, \
 { "nav_mode" }, \
 { "nav_climb" }, \
 { "fp_pitch" }, \
 { "fp_throttle" }, \
 { "fp_climb" }, \
 { "nav_shift" }, \
 { "nav_ground_speed_setpoint" }, \
 { "nav_ground_speed_pgain" }, \
 { "nav_survey_shift" }, \
 { "nav_survey_sweep" }, \
 { "multi_gps_mode" }, \
 { "avg_reset" }, \
 { "v_ctl_auto_throttle_cruise_throttle" }, \
 { "v_ctl_pitch_trim" }, \
 { "v_ctl_auto_throttle_pgain" }, \
 { "v_ctl_auto_throttle_igain" }, \
 { "v_ctl_auto_throttle_dgain" }, \
 { "v_ctl_auto_throttle_climb_throttle_increment" }, \
 { "v_ctl_auto_throttle_pitch_of_vz_pgain" }, \
 { "v_ctl_auto_throttle_pitch_of_vz_dgain" }, \
 { "v_ctl_auto_pitch_pgain" }, \
 { "v_ctl_auto_pitch_igain" }, \
 { "imu.body_to_imu.eulers_f.phi" }, \
 { "imu.body_to_imu.eulers_f.theta" }, \
 { "imu.body_to_imu.eulers_f.psi" }, \
 { "imu.b2i_set_current" }, \
 { "imu.gyro_abi_send_id" }, \
 { "imu.accel_abi_send_id" }, \
 { "imu.mag_abi_send_id" }, \
 { "usb_storage_status" }, \
 { "command_roll_trim" }, \
 { "command_pitch_trim" }, \
 { "command_yaw_trim" }, \
 { "h_ctl_roll_pgain" }, \
 { "h_ctl_roll_max_setpoint" }, \
 { "h_ctl_pitch_pgain" }, \
 { "h_ctl_pitch_dgain" }, \
 { "h_ctl_elevator_of_roll" }, \
 { "h_ctl_aileron_of_throttle" }, \
 { "h_ctl_roll_attitude_gain" }, \
 { "h_ctl_roll_rate_gain" }, \
 { "h_ctl_course_pgain" }, \
 { "h_ctl_course_dgain" }, \
 { "h_ctl_course_pre_bank_correction" }, \
 { "h_ctl_roll_slew" }, \
 { "gps_ubx.reset" }, \
 { "imu_health" }, \
 { "renorm_sqrt_count" }, \
 { "gps_ubx_ucenter.sw_ver_h" }, \
 { "gps_ubx_ucenter.sw_ver_l" }, \
 { "gps_ubx_ucenter.hw_ver_h" }, \
 { "gps_ubx_ucenter.hw_ver_l" }, \
 { "gps_ubx_ucenter.baud_init" }, \
 { "gps_ubx_ucenter.baud_run" }, \
};
#define SETTINGS_NAMES_SHORT { \
 "tel_mod_Ap" , \
 "tel_mod_Fbw" , \
 "tri_tri_rep_sta" , \
 "gps_ubl_gps_ubx_" , \
 "fli_rec_fli_rec_" , \
 "gps_ubx_uce_gps_" , \
 "mag_lis_mag_lis_" , \
 "mcu_reb" , \
 "aut_mod" , \
 "aut_lau" , \
 "aut_kil_thr" , \
 "fli_alt" , \
 "nav_cou" , \
 "nav_shi" , \
 "aut_fli_tim" , \
 "nav_rad" , \
 "pow_swi_sta" , \
 "nav_rad" , \
 "nav_cou" , \
 "nav_mod" , \
 "nav_cli" , \
 "fp_pit" , \
 "fp_thr" , \
 "fp_cli" , \
 "nav_shi" , \
 "nav_gro_spe_set" , \
 "nav_gro_spe_pga" , \
 "nav_sur_shi" , \
 "nav_sur_swe" , \
 "mul_gps_mod" , \
 "avg_res" , \
 "v_ctl_aut_thr_cr" , \
 "v_ctl_pit_tri" , \
 "v_ctl_aut_thr_pg" , \
 "v_ctl_aut_thr_ig" , \
 "v_ctl_aut_thr_dg" , \
 "v_ctl_aut_thr_cl" , \
 "v_ctl_aut_thr_pi" , \
 "v_ctl_aut_thr_pi" , \
 "v_ctl_aut_pit_pg" , \
 "v_ctl_aut_pit_ig" , \
 "imu_bod_to_imu_e" , \
 "imu_bod_to_imu_e" , \
 "imu_bod_to_imu_e" , \
 "imu_b2i_set_cur" , \
 "imu_gyr_abi_sen_" , \
 "imu_acc_abi_sen_" , \
 "imu_mag_abi_sen_" , \
 "usb_sto_sta" , \
 "com_rol_tri" , \
 "com_pit_tri" , \
 "com_yaw_tri" , \
 "h_ctl_rol_pga" , \
 "h_ctl_rol_max_se" , \
 "h_ctl_pit_pga" , \
 "h_ctl_pit_dga" , \
 "h_ctl_ele_of_rol" , \
 "h_ctl_ail_of_thr" , \
 "h_ctl_rol_att_ga" , \
 "h_ctl_rol_rat_ga" , \
 "h_ctl_cou_pga" , \
 "h_ctl_cou_dga" , \
 "h_ctl_cou_pre_ba" , \
 "h_ctl_rol_sle" , \
 "gps_ubx_res" , \
 "imu_hea" , \
 "ren_sqr_cou" , \
 "gps_ubx_uce_sw_v" , \
 "gps_ubx_uce_sw_v" , \
 "gps_ubx_uce_hw_v" , \
 "gps_ubx_uce_hw_v" , \
 "gps_ubx_uce_bau_" , \
 "gps_ubx_uce_bau_" , \
};
#define NB_SETTING 73
#define DlSetting(_idx, _value) { \
  switch (_idx) { \
    case 0: telemetry_mode_Ap = _value; break;\
    case 1: telemetry_mode_Fbw = _value; break;\
    case 2: trisonica_trisonica_report_status = _value; break;\
    case 3: gps_ublox_gps_ubx_periodic_check_status = _value; break;\
    case 4: flight_recorder_flight_recorder_periodic_status = _value; break;\
    case 5: gps_ubx_ucenter_gps_ubx_ucenter_periodic_status = _value; break;\
    case 6: mag_lis3mdl_mag_lis3mdl_report_status = _value; break;\
    case 7: mcu_reboot( _value ); break;\
    case 8: autopilot.mode = _value; break;\
    case 9: autopilot.launch = _value; break;\
    case 10: autopilot_KillThrottle( _value ); _value = autopilot.kill_throttle; break;\
    case 11: flight_altitude = _value; break;\
    case 12: nav_course = _value; break;\
    case 13: nav_IncreaseShift( _value ); _value = nav_shift; break;\
    case 14: autopilot_ResetFlightTimeAndLaunch( _value ); _value = autopilot.flight_time; break;\
    case 15: nav_SetNavRadius( _value ); _value = nav_radius; break;\
    case 16: power_switch_set( _value ); _value = power_switch_status; break;\
    case 17: nav_radius = _value; break;\
    case 18: nav_course = _value; break;\
    case 19: nav_mode = _value; break;\
    case 20: nav_climb = _value; break;\
    case 21: fp_pitch = _value; break;\
    case 22: fp_throttle = _value; break;\
    case 23: fp_climb = _value; break;\
    case 24: nav_IncreaseShift( _value ); _value = nav_shift; break;\
    case 25: nav_ground_speed_setpoint = _value; break;\
    case 26: nav_ground_speed_pgain = _value; break;\
    case 27: nav_survey_shift = _value; break;\
    case 28: nav_survey_sweep = _value; break;\
    case 29: multi_gps_mode = _value; break;\
    case 30: electrical_avg_reset( _value ); break;\
    case 31: guidance_v_SetCruiseThrottle( _value ); _value = v_ctl_auto_throttle_cruise_throttle; break;\
    case 32: v_ctl_pitch_trim = _value; break;\
    case 33: v_ctl_auto_throttle_pgain = _value; break;\
    case 34: v_ctl_auto_throttle_igain = _value; break;\
    case 35: v_ctl_auto_throttle_dgain = _value; break;\
    case 36: v_ctl_auto_throttle_climb_throttle_increment = _value; break;\
    case 37: v_ctl_auto_throttle_pitch_of_vz_pgain = _value; break;\
    case 38: v_ctl_auto_throttle_pitch_of_vz_dgain = _value; break;\
    case 39: v_ctl_auto_pitch_pgain = _value; break;\
    case 40: v_ctl_auto_pitch_igain = _value; break;\
    case 41: imu_SetBodyToImuPhi( _value ); _value = imu.body_to_imu.eulers_f.phi; break;\
    case 42: imu_SetBodyToImuTheta( _value ); _value = imu.body_to_imu.eulers_f.theta; break;\
    case 43: imu_SetBodyToImuPsi( _value ); _value = imu.body_to_imu.eulers_f.psi; break;\
    case 44: imu_SetBodyToImuCurrent( _value ); _value = imu.b2i_set_current; break;\
    case 45: imu.gyro_abi_send_id = _value; break;\
    case 46: imu.accel_abi_send_id = _value; break;\
    case 47: imu.mag_abi_send_id = _value; break;\
    case 48: usbStorage_enable_usb_storage( _value ); _value = usb_storage_status; break;\
    case 49: command_roll_trim = _value; break;\
    case 50: command_pitch_trim = _value; break;\
    case 51: command_yaw_trim = _value; break;\
    case 52: h_ctl_roll_pgain = _value; break;\
    case 53: h_ctl_roll_max_setpoint = _value; break;\
    case 54: h_ctl_pitch_pgain = _value; break;\
    case 55: h_ctl_pitch_dgain = _value; break;\
    case 56: h_ctl_elevator_of_roll = _value; break;\
    case 57: h_ctl_aileron_of_throttle = _value; break;\
    case 58: h_ctl_roll_attitude_gain = _value; break;\
    case 59: h_ctl_roll_rate_gain = _value; break;\
    case 60: h_ctl_course_pgain = _value; break;\
    case 61: h_ctl_course_dgain = _value; break;\
    case 62: h_ctl_course_pre_bank_correction = _value; break;\
    case 63: h_ctl_roll_slew = _value; break;\
    case 64: gps_ubx.reset = _value; break;\
    case 65: imu_health = _value; break;\
    case 66: renorm_sqrt_count = _value; break;\
    case 67: gps_ubx_ucenter.sw_ver_h = _value; break;\
    case 68: gps_ubx_ucenter.sw_ver_l = _value; break;\
    case 69: gps_ubx_ucenter.hw_ver_h = _value; break;\
    case 70: gps_ubx_ucenter.hw_ver_l = _value; break;\
    case 71: gps_ubx_ucenter.baud_init = _value; break;\
    case 72: gps_ubx_ucenter.baud_run = _value; break;\
    default: break;\
  }\
}
#define PeriodicSendDlValue(_trans, _dev) { \
  static uint8_t i;\
  float var;\
  if (i >= 73) i = 0;\
  switch (i) { \
    case 0: var = telemetry_mode_Ap; break;\
    case 1: var = telemetry_mode_Fbw; break;\
    case 2: var = trisonica_trisonica_report_status; break;\
    case 3: var = gps_ublox_gps_ubx_periodic_check_status; break;\
    case 4: var = flight_recorder_flight_recorder_periodic_status; break;\
    case 5: var = gps_ubx_ucenter_gps_ubx_ucenter_periodic_status; break;\
    case 6: var = mag_lis3mdl_mag_lis3mdl_report_status; break;\
    case 7: var = 0; break;\
    case 8: var = autopilot.mode; break;\
    case 9: var = autopilot.launch; break;\
    case 10: var = autopilot.kill_throttle; break;\
    case 11: var = flight_altitude; break;\
    case 12: var = nav_course; break;\
    case 13: var = nav_shift; break;\
    case 14: var = autopilot.flight_time; break;\
    case 15: var = nav_radius; break;\
    case 16: var = power_switch_status; break;\
    case 17: var = nav_radius; break;\
    case 18: var = nav_course; break;\
    case 19: var = nav_mode; break;\
    case 20: var = nav_climb; break;\
    case 21: var = fp_pitch; break;\
    case 22: var = fp_throttle; break;\
    case 23: var = fp_climb; break;\
    case 24: var = nav_shift; break;\
    case 25: var = nav_ground_speed_setpoint; break;\
    case 26: var = nav_ground_speed_pgain; break;\
    case 27: var = nav_survey_shift; break;\
    case 28: var = nav_survey_sweep; break;\
    case 29: var = multi_gps_mode; break;\
    case 30: var = 0; break;\
    case 31: var = v_ctl_auto_throttle_cruise_throttle; break;\
    case 32: var = v_ctl_pitch_trim; break;\
    case 33: var = v_ctl_auto_throttle_pgain; break;\
    case 34: var = v_ctl_auto_throttle_igain; break;\
    case 35: var = v_ctl_auto_throttle_dgain; break;\
    case 36: var = v_ctl_auto_throttle_climb_throttle_increment; break;\
    case 37: var = v_ctl_auto_throttle_pitch_of_vz_pgain; break;\
    case 38: var = v_ctl_auto_throttle_pitch_of_vz_dgain; break;\
    case 39: var = v_ctl_auto_pitch_pgain; break;\
    case 40: var = v_ctl_auto_pitch_igain; break;\
    case 41: var = imu.body_to_imu.eulers_f.phi; break;\
    case 42: var = imu.body_to_imu.eulers_f.theta; break;\
    case 43: var = imu.body_to_imu.eulers_f.psi; break;\
    case 44: var = imu.b2i_set_current; break;\
    case 45: var = imu.gyro_abi_send_id; break;\
    case 46: var = imu.accel_abi_send_id; break;\
    case 47: var = imu.mag_abi_send_id; break;\
    case 48: var = usb_storage_status; break;\
    case 49: var = command_roll_trim; break;\
    case 50: var = command_pitch_trim; break;\
    case 51: var = command_yaw_trim; break;\
    case 52: var = h_ctl_roll_pgain; break;\
    case 53: var = h_ctl_roll_max_setpoint; break;\
    case 54: var = h_ctl_pitch_pgain; break;\
    case 55: var = h_ctl_pitch_dgain; break;\
    case 56: var = h_ctl_elevator_of_roll; break;\
    case 57: var = h_ctl_aileron_of_throttle; break;\
    case 58: var = h_ctl_roll_attitude_gain; break;\
    case 59: var = h_ctl_roll_rate_gain; break;\
    case 60: var = h_ctl_course_pgain; break;\
    case 61: var = h_ctl_course_dgain; break;\
    case 62: var = h_ctl_course_pre_bank_correction; break;\
    case 63: var = h_ctl_roll_slew; break;\
    case 64: var = gps_ubx.reset; break;\
    case 65: var = imu_health; break;\
    case 66: var = renorm_sqrt_count; break;\
    case 67: var = gps_ubx_ucenter.sw_ver_h; break;\
    case 68: var = gps_ubx_ucenter.sw_ver_l; break;\
    case 69: var = gps_ubx_ucenter.hw_ver_h; break;\
    case 70: var = gps_ubx_ucenter.hw_ver_l; break;\
    case 71: var = gps_ubx_ucenter.baud_init; break;\
    case 72: var = gps_ubx_ucenter.baud_run; break;\
    default: var = 0.; break;\
  }\
  pprz_msg_send_DL_VALUE(_trans, _dev, AC_ID, &i, &var);\
  i++;\
}
static inline float settings_get_value(uint8_t i) {
  switch (i) {
    case 0: return telemetry_mode_Ap;
    case 1: return telemetry_mode_Fbw;
    case 2: return trisonica_trisonica_report_status;
    case 3: return gps_ublox_gps_ubx_periodic_check_status;
    case 4: return flight_recorder_flight_recorder_periodic_status;
    case 5: return gps_ubx_ucenter_gps_ubx_ucenter_periodic_status;
    case 6: return mag_lis3mdl_mag_lis3mdl_report_status;
    case 7: return 0;
    case 8: return autopilot.mode;
    case 9: return autopilot.launch;
    case 10: return autopilot.kill_throttle;
    case 11: return flight_altitude;
    case 12: return nav_course;
    case 13: return nav_shift;
    case 14: return autopilot.flight_time;
    case 15: return nav_radius;
    case 16: return power_switch_status;
    case 17: return nav_radius;
    case 18: return nav_course;
    case 19: return nav_mode;
    case 20: return nav_climb;
    case 21: return fp_pitch;
    case 22: return fp_throttle;
    case 23: return fp_climb;
    case 24: return nav_shift;
    case 25: return nav_ground_speed_setpoint;
    case 26: return nav_ground_speed_pgain;
    case 27: return nav_survey_shift;
    case 28: return nav_survey_sweep;
    case 29: return multi_gps_mode;
    case 30: return 0;
    case 31: return v_ctl_auto_throttle_cruise_throttle;
    case 32: return v_ctl_pitch_trim;
    case 33: return v_ctl_auto_throttle_pgain;
    case 34: return v_ctl_auto_throttle_igain;
    case 35: return v_ctl_auto_throttle_dgain;
    case 36: return v_ctl_auto_throttle_climb_throttle_increment;
    case 37: return v_ctl_auto_throttle_pitch_of_vz_pgain;
    case 38: return v_ctl_auto_throttle_pitch_of_vz_dgain;
    case 39: return v_ctl_auto_pitch_pgain;
    case 40: return v_ctl_auto_pitch_igain;
    case 41: return imu.body_to_imu.eulers_f.phi;
    case 42: return imu.body_to_imu.eulers_f.theta;
    case 43: return imu.body_to_imu.eulers_f.psi;
    case 44: return imu.b2i_set_current;
    case 45: return imu.gyro_abi_send_id;
    case 46: return imu.accel_abi_send_id;
    case 47: return imu.mag_abi_send_id;
    case 48: return usb_storage_status;
    case 49: return command_roll_trim;
    case 50: return command_pitch_trim;
    case 51: return command_yaw_trim;
    case 52: return h_ctl_roll_pgain;
    case 53: return h_ctl_roll_max_setpoint;
    case 54: return h_ctl_pitch_pgain;
    case 55: return h_ctl_pitch_dgain;
    case 56: return h_ctl_elevator_of_roll;
    case 57: return h_ctl_aileron_of_throttle;
    case 58: return h_ctl_roll_attitude_gain;
    case 59: return h_ctl_roll_rate_gain;
    case 60: return h_ctl_course_pgain;
    case 61: return h_ctl_course_dgain;
    case 62: return h_ctl_course_pre_bank_correction;
    case 63: return h_ctl_roll_slew;
    case 64: return gps_ubx.reset;
    case 65: return imu_health;
    case 66: return renorm_sqrt_count;
    case 67: return gps_ubx_ucenter.sw_ver_h;
    case 68: return gps_ubx_ucenter.sw_ver_l;
    case 69: return gps_ubx_ucenter.hw_ver_h;
    case 70: return gps_ubx_ucenter.hw_ver_l;
    case 71: return gps_ubx_ucenter.baud_init;
    case 72: return gps_ubx_ucenter.baud_run;
    default: return 0.;
  }
}

/* Persistent Settings */
struct PersistentSettings {
  float s_0; /* imu.body_to_imu.eulers_f.phi */
  float s_1; /* imu.body_to_imu.eulers_f.theta */
  float s_2; /* imu.body_to_imu.eulers_f.psi */
};

extern struct PersistentSettings pers_settings;

static inline void persistent_settings_store( void ) {
  pers_settings.s_0 = imu.body_to_imu.eulers_f.phi;
  pers_settings.s_1 = imu.body_to_imu.eulers_f.theta;
  pers_settings.s_2 = imu.body_to_imu.eulers_f.psi;
}

static inline void persistent_settings_load( void ) {
  imu_SetBodyToImuPhi( pers_settings.s_0 );
  imu_SetBodyToImuTheta( pers_settings.s_1 );
  imu_SetBodyToImuPsi( pers_settings.s_2 );
}

#endif // SETTINGS_H
