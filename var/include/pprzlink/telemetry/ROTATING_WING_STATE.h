/** @file
 *  @brief PPRZLink message header for ROTATING_WING_STATE in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_ROTATING_WING_STATE_H_
#define _VAR_MESSAGES_telemetry_ROTATING_WING_STATE_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_ROTATING_WING_STATE 181
#define PPRZ_MSG_ID_ROTATING_WING_STATE 181

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_ROTATING_WING_STATE _send_msg(ROTATING_WING_STATE,PPRZLINK_DEFAULT_VER)

/**
 * Sends a ROTATING_WING_STATE message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _current_state 
 * @param _desired_state 
 * @param _wing_angle_deg 
 * @param _wing_angle_deg_sp 
 * @param _ADC_position 
 * @param _pprz_cmd 
 */
static inline void pprzlink_msg_v2_send_ROTATING_WING_STATE(struct pprzlink_msg * msg, uint8_t *_current_state, uint8_t *_desired_state, float *_wing_angle_deg, float *_wing_angle_deg_sp, uint16_t *_ADC_position, int32_t *_pprz_cmd) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+1+1+4+4+2+4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+1+1+4+4+2+4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_ROTATING_WING_STATE, "ROTATING_WING_STATE");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _current_state, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, (void *) _desired_state, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _wing_angle_deg, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _wing_angle_deg_sp, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT16, DL_FORMAT_SCALAR, (void *) _ADC_position, 2);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_INT32, DL_FORMAT_SCALAR, (void *) _pprz_cmd, 4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_ROTATING_WING_STATE pprz_msg_send_ROTATING_WING_STATE
#define DOWNLINK_SEND_ROTATING_WING_STATE(_trans, _dev, current_state, desired_state, wing_angle_deg, wing_angle_deg_sp, ADC_position, pprz_cmd) pprz_msg_send_ROTATING_WING_STATE(&((_trans).trans_tx), &((_dev).device), AC_ID, current_state, desired_state, wing_angle_deg, wing_angle_deg_sp, ADC_position, pprz_cmd)
/**
 * Sends a ROTATING_WING_STATE message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _current_state 
 * @param _desired_state 
 * @param _wing_angle_deg 
 * @param _wing_angle_deg_sp 
 * @param _ADC_position 
 * @param _pprz_cmd 
 */
static inline void pprz_msg_send_ROTATING_WING_STATE(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, uint8_t *_current_state, uint8_t *_desired_state, float *_wing_angle_deg, float *_wing_angle_deg_sp, uint16_t *_ADC_position, int32_t *_pprz_cmd) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_ROTATING_WING_STATE(&msg,_current_state,_desired_state,_wing_angle_deg,_wing_angle_deg_sp,_ADC_position,_pprz_cmd);
}


#else // DOWNLINK

#define DOWNLINK_SEND_ROTATING_WING_STATE(_trans, _dev, current_state, desired_state, wing_angle_deg, wing_angle_deg_sp, ADC_position, pprz_cmd) {}
static inline void pprz_send_msg_ROTATING_WING_STATE(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), uint8_t *_current_state __attribute__((unused)), uint8_t *_desired_state __attribute__((unused)), float *_wing_angle_deg __attribute__((unused)), float *_wing_angle_deg_sp __attribute__((unused)), uint16_t *_ADC_position __attribute__((unused)), int32_t *_pprz_cmd __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field current_state in message ROTATING_WING_STATE
  *
  * @param _payload : a pointer to the ROTATING_WING_STATE message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROTATING_WING_STATE_current_state(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 4);
}


/** Getter for field desired_state in message ROTATING_WING_STATE
  *
  * @param _payload : a pointer to the ROTATING_WING_STATE message
  * @return 
  */
static inline uint8_t pprzlink_get_DL_ROTATING_WING_STATE_desired_state(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint8_t(_payload, 5);
}


/** Getter for field wing_angle_deg in message ROTATING_WING_STATE
  *
  * @param _payload : a pointer to the ROTATING_WING_STATE message
  * @return 
  */
static inline float pprzlink_get_DL_ROTATING_WING_STATE_wing_angle_deg(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 6);
}


/** Getter for field wing_angle_deg_sp in message ROTATING_WING_STATE
  *
  * @param _payload : a pointer to the ROTATING_WING_STATE message
  * @return 
  */
static inline float pprzlink_get_DL_ROTATING_WING_STATE_wing_angle_deg_sp(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 10);
}


/** Getter for field ADC_position in message ROTATING_WING_STATE
  *
  * @param _payload : a pointer to the ROTATING_WING_STATE message
  * @return 
  */
static inline uint16_t pprzlink_get_DL_ROTATING_WING_STATE_ADC_position(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_uint16_t(_payload, 14);
}


/** Getter for field pprz_cmd in message ROTATING_WING_STATE
  *
  * @param _payload : a pointer to the ROTATING_WING_STATE message
  * @return 
  */
static inline int32_t pprzlink_get_DL_ROTATING_WING_STATE_pprz_cmd(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_int32_t(_payload, 16);
}


/* Compatibility macros */
#define DL_ROTATING_WING_STATE_current_state(_payload) pprzlink_get_DL_ROTATING_WING_STATE_current_state(_payload)
#define DL_ROTATING_WING_STATE_desired_state(_payload) pprzlink_get_DL_ROTATING_WING_STATE_desired_state(_payload)
#define DL_ROTATING_WING_STATE_wing_angle_deg(_payload) pprzlink_get_DL_ROTATING_WING_STATE_wing_angle_deg(_payload)
#define DL_ROTATING_WING_STATE_wing_angle_deg_sp(_payload) pprzlink_get_DL_ROTATING_WING_STATE_wing_angle_deg_sp(_payload)
#define DL_ROTATING_WING_STATE_ADC_position(_payload) pprzlink_get_DL_ROTATING_WING_STATE_ADC_position(_payload)
#define DL_ROTATING_WING_STATE_pprz_cmd(_payload) pprzlink_get_DL_ROTATING_WING_STATE_pprz_cmd(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_ROTATING_WING_STATE_H_

