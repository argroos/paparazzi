/** @file
 *  @brief PPRZLink message header for INS_FLOW_INFO in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_INS_FLOW_INFO_H_
#define _VAR_MESSAGES_telemetry_INS_FLOW_INFO_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_INS_FLOW_INFO 158
#define PPRZ_MSG_ID_INS_FLOW_INFO 158

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_INS_FLOW_INFO _send_msg(INS_FLOW_INFO,PPRZLINK_DEFAULT_VER)

/**
 * Sends a INS_FLOW_INFO message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _vy 
 * @param _phi 
 * @param _p 
 * @param _vx 
 * @param _theta 
 * @param _q 
 * @param _z 
 * @param _vz 
 * @param _vy_GT 
 * @param _phi_GT 
 * @param _p_GT 
 * @param _vx_GT 
 * @param _theta_GT 
 * @param _q_GT 
 * @param _z_GT 
 * @param _vz_GT 
 * @param _thrust_bias 
 * @param _use_filter 
 */
static inline void pprzlink_msg_v2_send_INS_FLOW_INFO(struct pprzlink_msg * msg, float *_vy, float *_phi, float *_p, float *_vx, float *_theta, float *_q, float *_z, float *_vz, float *_vy_GT, float *_phi_GT, float *_p_GT, float *_vx_GT, float *_theta_GT, float *_q_GT, float *_z_GT, float *_vz_GT, float *_thrust_bias, int32_t *_use_filter) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_INS_FLOW_INFO, "INS_FLOW_INFO");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vy, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vx, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _q, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _z, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vz, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vy_GT, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _phi_GT, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _p_GT, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vx_GT, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _theta_GT, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _q_GT, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _z_GT, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _vz_GT, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _thrust_bias, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _use_filter, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_INS_FLOW_INFO pprz_msg_send_INS_FLOW_INFO
#define DOWNLINK_SEND_INS_FLOW_INFO(_trans, _dev, vy, phi, p, vx, theta, q, z, vz, vy_GT, phi_GT, p_GT, vx_GT, theta_GT, q_GT, z_GT, vz_GT, thrust_bias, use_filter) pprz_msg_send_INS_FLOW_INFO(&((_trans).trans_tx), &((_dev).device), AC_ID, vy, phi, p, vx, theta, q, z, vz, vy_GT, phi_GT, p_GT, vx_GT, theta_GT, q_GT, z_GT, vz_GT, thrust_bias, use_filter)
/**
 * Sends a INS_FLOW_INFO message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _vy 
 * @param _phi 
 * @param _p 
 * @param _vx 
 * @param _theta 
 * @param _q 
 * @param _z 
 * @param _vz 
 * @param _vy_GT 
 * @param _phi_GT 
 * @param _p_GT 
 * @param _vx_GT 
 * @param _theta_GT 
 * @param _q_GT 
 * @param _z_GT 
 * @param _vz_GT 
 * @param _thrust_bias 
 * @param _use_filter 
 */
static inline void pprz_msg_send_INS_FLOW_INFO(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_vy, float *_phi, float *_p, float *_vx, float *_theta, float *_q, float *_z, float *_vz, float *_vy_GT, float *_phi_GT, float *_p_GT, float *_vx_GT, float *_theta_GT, float *_q_GT, float *_z_GT, float *_vz_GT, float *_thrust_bias, int32_t *_use_filter) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_INS_FLOW_INFO(&msg,_vy,_phi,_p,_vx,_theta,_q,_z,_vz,_vy_GT,_phi_GT,_p_GT,_vx_GT,_theta_GT,_q_GT,_z_GT,_vz_GT,_thrust_bias,_use_filter);
}


#else // DOWNLINK

#define DOWNLINK_SEND_INS_FLOW_INFO(_trans, _dev, vy, phi, p, vx, theta, q, z, vz, vy_GT, phi_GT, p_GT, vx_GT, theta_GT, q_GT, z_GT, vz_GT, thrust_bias, use_filter) {}
static inline void pprz_send_msg_INS_FLOW_INFO(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_vy __attribute__((unused)), float *_phi __attribute__((unused)), float *_p __attribute__((unused)), float *_vx __attribute__((unused)), float *_theta __attribute__((unused)), float *_q __attribute__((unused)), float *_z __attribute__((unused)), float *_vz __attribute__((unused)), float *_vy_GT __attribute__((unused)), float *_phi_GT __attribute__((unused)), float *_p_GT __attribute__((unused)), float *_vx_GT __attribute__((unused)), float *_theta_GT __attribute__((unused)), float *_q_GT __attribute__((unused)), float *_z_GT __attribute__((unused)), float *_vz_GT __attribute__((unused)), float *_thrust_bias __attribute__((unused)), int32_t *_use_filter __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field vy in message INS_FLOW_INFO
  *
  * @param _payload : a pointer to the INS_FLOW_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_INS_FLOW_INFO_vy(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field phi in message INS_FLOW_INFO
  *
  * @param _payload : a pointer to the INS_FLOW_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_INS_FLOW_INFO_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field p in message INS_FLOW_INFO
  *
  * @param _payload : a pointer to the INS_FLOW_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_INS_FLOW_INFO_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field vx in message INS_FLOW_INFO
  *
  * @param _payload : a pointer to the INS_FLOW_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_INS_FLOW_INFO_vx(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field theta in message INS_FLOW_INFO
  *
  * @param _payload : a pointer to the INS_FLOW_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_INS_FLOW_INFO_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field q in message INS_FLOW_INFO
  *
  * @param _payload : a pointer to the INS_FLOW_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_INS_FLOW_INFO_q(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field z in message INS_FLOW_INFO
  *
  * @param _payload : a pointer to the INS_FLOW_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_INS_FLOW_INFO_z(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field vz in message INS_FLOW_INFO
  *
  * @param _payload : a pointer to the INS_FLOW_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_INS_FLOW_INFO_vz(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field vy_GT in message INS_FLOW_INFO
  *
  * @param _payload : a pointer to the INS_FLOW_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_INS_FLOW_INFO_vy_GT(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/** Getter for field phi_GT in message INS_FLOW_INFO
  *
  * @param _payload : a pointer to the INS_FLOW_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_INS_FLOW_INFO_phi_GT(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 40);
}


/** Getter for field p_GT in message INS_FLOW_INFO
  *
  * @param _payload : a pointer to the INS_FLOW_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_INS_FLOW_INFO_p_GT(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 44);
}


/** Getter for field vx_GT in message INS_FLOW_INFO
  *
  * @param _payload : a pointer to the INS_FLOW_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_INS_FLOW_INFO_vx_GT(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 48);
}


/** Getter for field theta_GT in message INS_FLOW_INFO
  *
  * @param _payload : a pointer to the INS_FLOW_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_INS_FLOW_INFO_theta_GT(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 52);
}


/** Getter for field q_GT in message INS_FLOW_INFO
  *
  * @param _payload : a pointer to the INS_FLOW_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_INS_FLOW_INFO_q_GT(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 56);
}


/** Getter for field z_GT in message INS_FLOW_INFO
  *
  * @param _payload : a pointer to the INS_FLOW_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_INS_FLOW_INFO_z_GT(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 60);
}


/** Getter for field vz_GT in message INS_FLOW_INFO
  *
  * @param _payload : a pointer to the INS_FLOW_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_INS_FLOW_INFO_vz_GT(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 64);
}


/** Getter for field thrust_bias in message INS_FLOW_INFO
  *
  * @param _payload : a pointer to the INS_FLOW_INFO message
  * @return 
  */
static inline float pprzlink_get_DL_INS_FLOW_INFO_thrust_bias(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 68);
}


/** Getter for field use_filter in message INS_FLOW_INFO
  *
  * @param _payload : a pointer to the INS_FLOW_INFO message
  * @return 
  */
static inline int32_t pprzlink_get_DL_INS_FLOW_INFO_use_filter(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 72);
}


/* Compatibility macros */
#define DL_INS_FLOW_INFO_vy(_payload) pprzlink_get_DL_INS_FLOW_INFO_vy(_payload)
#define DL_INS_FLOW_INFO_phi(_payload) pprzlink_get_DL_INS_FLOW_INFO_phi(_payload)
#define DL_INS_FLOW_INFO_p(_payload) pprzlink_get_DL_INS_FLOW_INFO_p(_payload)
#define DL_INS_FLOW_INFO_vx(_payload) pprzlink_get_DL_INS_FLOW_INFO_vx(_payload)
#define DL_INS_FLOW_INFO_theta(_payload) pprzlink_get_DL_INS_FLOW_INFO_theta(_payload)
#define DL_INS_FLOW_INFO_q(_payload) pprzlink_get_DL_INS_FLOW_INFO_q(_payload)
#define DL_INS_FLOW_INFO_z(_payload) pprzlink_get_DL_INS_FLOW_INFO_z(_payload)
#define DL_INS_FLOW_INFO_vz(_payload) pprzlink_get_DL_INS_FLOW_INFO_vz(_payload)
#define DL_INS_FLOW_INFO_vy_GT(_payload) pprzlink_get_DL_INS_FLOW_INFO_vy_GT(_payload)
#define DL_INS_FLOW_INFO_phi_GT(_payload) pprzlink_get_DL_INS_FLOW_INFO_phi_GT(_payload)
#define DL_INS_FLOW_INFO_p_GT(_payload) pprzlink_get_DL_INS_FLOW_INFO_p_GT(_payload)
#define DL_INS_FLOW_INFO_vx_GT(_payload) pprzlink_get_DL_INS_FLOW_INFO_vx_GT(_payload)
#define DL_INS_FLOW_INFO_theta_GT(_payload) pprzlink_get_DL_INS_FLOW_INFO_theta_GT(_payload)
#define DL_INS_FLOW_INFO_q_GT(_payload) pprzlink_get_DL_INS_FLOW_INFO_q_GT(_payload)
#define DL_INS_FLOW_INFO_z_GT(_payload) pprzlink_get_DL_INS_FLOW_INFO_z_GT(_payload)
#define DL_INS_FLOW_INFO_vz_GT(_payload) pprzlink_get_DL_INS_FLOW_INFO_vz_GT(_payload)
#define DL_INS_FLOW_INFO_thrust_bias(_payload) pprzlink_get_DL_INS_FLOW_INFO_thrust_bias(_payload)
#define DL_INS_FLOW_INFO_use_filter(_payload) pprzlink_get_DL_INS_FLOW_INFO_use_filter(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_INS_FLOW_INFO_H_

