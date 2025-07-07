/** @file
 *  @brief PPRZLink message header for STAB_ATTITUDE in class telemetry
 *
 *  
 *  @see http://paparazziuav.org
 */

#ifndef _VAR_MESSAGES_telemetry_STAB_ATTITUDE_H_
#define _VAR_MESSAGES_telemetry_STAB_ATTITUDE_H_


#include "pprzlink/pprzlink_device.h"
#include "pprzlink/pprzlink_transport.h"
#include "pprzlink/pprzlink_utils.h"
#include "pprzlink/pprzlink_message.h"


#ifdef __cplusplus
extern "C" {
#endif

#if DOWNLINK

#define DL_STAB_ATTITUDE 216
#define PPRZ_MSG_ID_STAB_ATTITUDE 216

/**
 * Macro that redirect calls to the default version of pprzlink API
 * Used for compatibility between versions.
 */
#define pprzlink_msg_send_STAB_ATTITUDE _send_msg(STAB_ATTITUDE,PPRZLINK_DEFAULT_VER)

/**
 * Sends a STAB_ATTITUDE message (API V2.0 version)
 *
 * @param msg the pprzlink_msg structure for this message
 * @param _phi 
 * @param _theta 
 * @param _psi 
 * @param _phi_ref 
 * @param _theta_ref 
 * @param _psi_ref 
 * @param _angular_rate_p 
 * @param _angular_rate_q 
 * @param _angular_rate_r 
 * @param _angular_rate_ref_p 
 * @param _angular_rate_ref_q 
 * @param _angular_rate_ref_r 
 * @param _angular_accel_p 
 * @param _angular_accel_q 
 * @param _angular_accel_r 
 * @param _angular_accel_ref_p 
 * @param _angular_accel_ref_q 
 * @param _angular_accel_ref_r 
 * @param nb_nu,_nu Input of control allocation
 * @param nb_u,_u Output of control allocation
 */
static inline void pprzlink_msg_v2_send_STAB_ATTITUDE(struct pprzlink_msg * msg, float *_phi, float *_theta, float *_psi, float *_phi_ref, float *_theta_ref, float *_psi_ref, float *_angular_rate_p, float *_angular_rate_q, float *_angular_rate_r, float *_angular_rate_ref_p, float *_angular_rate_ref_q, float *_angular_rate_ref_r, float *_angular_accel_p, float *_angular_accel_q, float *_angular_accel_r, float *_angular_accel_ref_p, float *_angular_accel_ref_q, float *_angular_accel_ref_r, uint8_t nb_nu, float *_nu, uint8_t nb_u, float *_u) {
#if PPRZLINK_ENABLE_FD
  long _FD = 0; /* can be an address, an index, a file descriptor, ... */
#endif
  const uint8_t size = msg->trans->size_of(msg, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+1+nb_nu*4+1+nb_u*4);
  if (msg->trans->check_available_space(msg, _FD_ADDR, size)) {
    msg->trans->count_bytes(msg, size);
    msg->trans->start_message(msg, _FD, /* msg header overhead */4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+1+nb_nu*4+1+nb_u*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, &(msg->sender_id), 1);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, msg->receiver_id, NULL);
    uint8_t comp_class = (msg->component_id & 0x0F) << 4 | (1 & 0x0F);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, comp_class, NULL);
    msg->trans->put_named_byte(msg, _FD, DL_TYPE_UINT8, DL_FORMAT_SCALAR, DL_STAB_ATTITUDE, "STAB_ATTITUDE");
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _phi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _theta, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _psi, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _phi_ref, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _theta_ref, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _psi_ref, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _angular_rate_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _angular_rate_q, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _angular_rate_r, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _angular_rate_ref_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _angular_rate_ref_q, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _angular_rate_ref_r, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _angular_accel_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _angular_accel_q, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _angular_accel_r, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _angular_accel_ref_p, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _angular_accel_ref_q, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_SCALAR, (void *) _angular_accel_ref_r, 4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_nu, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_ARRAY, (void *) _nu, nb_nu*4);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_ARRAY_LENGTH, DL_FORMAT_SCALAR, (void *) &nb_u, 1);
    msg->trans->put_bytes(msg, _FD, DL_TYPE_FLOAT, DL_FORMAT_ARRAY, (void *) _u, nb_u*4);
    msg->trans->end_message(msg, _FD);
  } else
        msg->trans->overrun(msg);
}

// Compatibility with the protocol v1.0 API
#define pprzlink_msg_v1_send_STAB_ATTITUDE pprz_msg_send_STAB_ATTITUDE
#define DOWNLINK_SEND_STAB_ATTITUDE(_trans, _dev, phi, theta, psi, phi_ref, theta_ref, psi_ref, angular_rate_p, angular_rate_q, angular_rate_r, angular_rate_ref_p, angular_rate_ref_q, angular_rate_ref_r, angular_accel_p, angular_accel_q, angular_accel_r, angular_accel_ref_p, angular_accel_ref_q, angular_accel_ref_r, nb_nu, nu, nb_u, u) pprz_msg_send_STAB_ATTITUDE(&((_trans).trans_tx), &((_dev).device), AC_ID, phi, theta, psi, phi_ref, theta_ref, psi_ref, angular_rate_p, angular_rate_q, angular_rate_r, angular_rate_ref_p, angular_rate_ref_q, angular_rate_ref_r, angular_accel_p, angular_accel_q, angular_accel_r, angular_accel_ref_p, angular_accel_ref_q, angular_accel_ref_r, nb_nu, nu, nb_u, u)
/**
 * Sends a STAB_ATTITUDE message (API V1.0 version)
 *
 * @param trans A pointer to the transport_tx structure used for sending the message
 * @param dev A pointer to the link_device structure through which the message will be sent
 * @param ac_id The id of the sender of the message
 * @param _phi 
 * @param _theta 
 * @param _psi 
 * @param _phi_ref 
 * @param _theta_ref 
 * @param _psi_ref 
 * @param _angular_rate_p 
 * @param _angular_rate_q 
 * @param _angular_rate_r 
 * @param _angular_rate_ref_p 
 * @param _angular_rate_ref_q 
 * @param _angular_rate_ref_r 
 * @param _angular_accel_p 
 * @param _angular_accel_q 
 * @param _angular_accel_r 
 * @param _angular_accel_ref_p 
 * @param _angular_accel_ref_q 
 * @param _angular_accel_ref_r 
 * @param nb_nu,_nu Input of control allocation
 * @param nb_u,_u Output of control allocation
 */
static inline void pprz_msg_send_STAB_ATTITUDE(struct transport_tx *trans, struct link_device *dev, uint8_t ac_id, float *_phi, float *_theta, float *_psi, float *_phi_ref, float *_theta_ref, float *_psi_ref, float *_angular_rate_p, float *_angular_rate_q, float *_angular_rate_r, float *_angular_rate_ref_p, float *_angular_rate_ref_q, float *_angular_rate_ref_r, float *_angular_accel_p, float *_angular_accel_q, float *_angular_accel_r, float *_angular_accel_ref_p, float *_angular_accel_ref_q, float *_angular_accel_ref_r, uint8_t nb_nu, float *_nu, uint8_t nb_u, float *_u) {
    struct pprzlink_msg msg;
    msg.trans = trans;
    msg.dev = dev;
    msg.sender_id = ac_id;
    msg.receiver_id = 0;
    msg.component_id = 0;
    pprzlink_msg_v2_send_STAB_ATTITUDE(&msg,_phi,_theta,_psi,_phi_ref,_theta_ref,_psi_ref,_angular_rate_p,_angular_rate_q,_angular_rate_r,_angular_rate_ref_p,_angular_rate_ref_q,_angular_rate_ref_r,_angular_accel_p,_angular_accel_q,_angular_accel_r,_angular_accel_ref_p,_angular_accel_ref_q,_angular_accel_ref_r,nb_nu,_nu,nb_u,_u);
}


#else // DOWNLINK

#define DOWNLINK_SEND_STAB_ATTITUDE(_trans, _dev, phi, theta, psi, phi_ref, theta_ref, psi_ref, angular_rate_p, angular_rate_q, angular_rate_r, angular_rate_ref_p, angular_rate_ref_q, angular_rate_ref_r, angular_accel_p, angular_accel_q, angular_accel_r, angular_accel_ref_p, angular_accel_ref_q, angular_accel_ref_r, nb_nu, nu, nb_u, u) {}
static inline void pprz_send_msg_STAB_ATTITUDE(struct transport_tx *trans __attribute__((unused)), struct link_device *dev __attribute__((unused)), uint8_t ac_id __attribute__((unused)), float *_phi __attribute__((unused)), float *_theta __attribute__((unused)), float *_psi __attribute__((unused)), float *_phi_ref __attribute__((unused)), float *_theta_ref __attribute__((unused)), float *_psi_ref __attribute__((unused)), float *_angular_rate_p __attribute__((unused)), float *_angular_rate_q __attribute__((unused)), float *_angular_rate_r __attribute__((unused)), float *_angular_rate_ref_p __attribute__((unused)), float *_angular_rate_ref_q __attribute__((unused)), float *_angular_rate_ref_r __attribute__((unused)), float *_angular_accel_p __attribute__((unused)), float *_angular_accel_q __attribute__((unused)), float *_angular_accel_r __attribute__((unused)), float *_angular_accel_ref_p __attribute__((unused)), float *_angular_accel_ref_q __attribute__((unused)), float *_angular_accel_ref_r __attribute__((unused)), uint8_t nb_nu __attribute__((unused)), float *_nu __attribute__((unused)), uint8_t nb_u __attribute__((unused)), float *_u __attribute__((unused))) {}

#endif // DOWNLINK


/** Getter for field phi in message STAB_ATTITUDE
  *
  * @param _payload : a pointer to the STAB_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_phi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 4);
}


/** Getter for field theta in message STAB_ATTITUDE
  *
  * @param _payload : a pointer to the STAB_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_theta(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 8);
}


/** Getter for field psi in message STAB_ATTITUDE
  *
  * @param _payload : a pointer to the STAB_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_psi(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 12);
}


/** Getter for field phi_ref in message STAB_ATTITUDE
  *
  * @param _payload : a pointer to the STAB_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_phi_ref(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 16);
}


/** Getter for field theta_ref in message STAB_ATTITUDE
  *
  * @param _payload : a pointer to the STAB_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_theta_ref(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 20);
}


/** Getter for field psi_ref in message STAB_ATTITUDE
  *
  * @param _payload : a pointer to the STAB_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_psi_ref(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 24);
}


/** Getter for field angular_rate_p in message STAB_ATTITUDE
  *
  * @param _payload : a pointer to the STAB_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_angular_rate_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 28);
}


/** Getter for field angular_rate_q in message STAB_ATTITUDE
  *
  * @param _payload : a pointer to the STAB_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_angular_rate_q(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 32);
}


/** Getter for field angular_rate_r in message STAB_ATTITUDE
  *
  * @param _payload : a pointer to the STAB_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_angular_rate_r(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 36);
}


/** Getter for field angular_rate_ref_p in message STAB_ATTITUDE
  *
  * @param _payload : a pointer to the STAB_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_angular_rate_ref_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 40);
}


/** Getter for field angular_rate_ref_q in message STAB_ATTITUDE
  *
  * @param _payload : a pointer to the STAB_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_angular_rate_ref_q(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 44);
}


/** Getter for field angular_rate_ref_r in message STAB_ATTITUDE
  *
  * @param _payload : a pointer to the STAB_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_angular_rate_ref_r(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 48);
}


/** Getter for field angular_accel_p in message STAB_ATTITUDE
  *
  * @param _payload : a pointer to the STAB_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_angular_accel_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 52);
}


/** Getter for field angular_accel_q in message STAB_ATTITUDE
  *
  * @param _payload : a pointer to the STAB_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_angular_accel_q(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 56);
}


/** Getter for field angular_accel_r in message STAB_ATTITUDE
  *
  * @param _payload : a pointer to the STAB_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_angular_accel_r(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 60);
}


/** Getter for field angular_accel_ref_p in message STAB_ATTITUDE
  *
  * @param _payload : a pointer to the STAB_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_angular_accel_ref_p(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 64);
}


/** Getter for field angular_accel_ref_q in message STAB_ATTITUDE
  *
  * @param _payload : a pointer to the STAB_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_angular_accel_ref_q(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 68);
}


/** Getter for field angular_accel_ref_r in message STAB_ATTITUDE
  *
  * @param _payload : a pointer to the STAB_ATTITUDE message
  * @return 
  */
static inline float pprzlink_get_DL_STAB_ATTITUDE_angular_accel_ref_r(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float(_payload, 72);
}

/** Getter for length of array nu in message STAB_ATTITUDE
 *
 * @return nu : Input of control allocation
 */
 static inline uint8_t pprzlink_get_STAB_ATTITUDE_nu_length(__attribute__ ((unused)) void* _payload) {
    return _PPRZ_VAL_len_aligned(_payload, 76);
}

/** Getter for field nu in message STAB_ATTITUDE
  *
  * @param _payload : a pointer to the STAB_ATTITUDE message
  * @return Input of control allocation
  */
static inline float * pprzlink_get_DL_STAB_ATTITUDE_nu(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float_array(_payload, 77);
}

/** Getter for length of array u in message STAB_ATTITUDE
 *
 * @return u : Output of control allocation
 */
 static inline uint8_t pprzlink_get_STAB_ATTITUDE_u_length(__attribute__ ((unused)) void* _payload) {
    return _PPRZ_VAL_len_aligned(_payload, 77);
}

/** Getter for field u in message STAB_ATTITUDE
  *
  * @param _payload : a pointer to the STAB_ATTITUDE message
  * @return Output of control allocation
  */
static inline float * pprzlink_get_DL_STAB_ATTITUDE_u(uint8_t * _payload __attribute__((unused)))
{
    return _PPRZ_VAL_float_array(_payload, 78);
}


/* Compatibility macros */
#define DL_STAB_ATTITUDE_phi(_payload) pprzlink_get_DL_STAB_ATTITUDE_phi(_payload)
#define DL_STAB_ATTITUDE_theta(_payload) pprzlink_get_DL_STAB_ATTITUDE_theta(_payload)
#define DL_STAB_ATTITUDE_psi(_payload) pprzlink_get_DL_STAB_ATTITUDE_psi(_payload)
#define DL_STAB_ATTITUDE_phi_ref(_payload) pprzlink_get_DL_STAB_ATTITUDE_phi_ref(_payload)
#define DL_STAB_ATTITUDE_theta_ref(_payload) pprzlink_get_DL_STAB_ATTITUDE_theta_ref(_payload)
#define DL_STAB_ATTITUDE_psi_ref(_payload) pprzlink_get_DL_STAB_ATTITUDE_psi_ref(_payload)
#define DL_STAB_ATTITUDE_angular_rate_p(_payload) pprzlink_get_DL_STAB_ATTITUDE_angular_rate_p(_payload)
#define DL_STAB_ATTITUDE_angular_rate_q(_payload) pprzlink_get_DL_STAB_ATTITUDE_angular_rate_q(_payload)
#define DL_STAB_ATTITUDE_angular_rate_r(_payload) pprzlink_get_DL_STAB_ATTITUDE_angular_rate_r(_payload)
#define DL_STAB_ATTITUDE_angular_rate_ref_p(_payload) pprzlink_get_DL_STAB_ATTITUDE_angular_rate_ref_p(_payload)
#define DL_STAB_ATTITUDE_angular_rate_ref_q(_payload) pprzlink_get_DL_STAB_ATTITUDE_angular_rate_ref_q(_payload)
#define DL_STAB_ATTITUDE_angular_rate_ref_r(_payload) pprzlink_get_DL_STAB_ATTITUDE_angular_rate_ref_r(_payload)
#define DL_STAB_ATTITUDE_angular_accel_p(_payload) pprzlink_get_DL_STAB_ATTITUDE_angular_accel_p(_payload)
#define DL_STAB_ATTITUDE_angular_accel_q(_payload) pprzlink_get_DL_STAB_ATTITUDE_angular_accel_q(_payload)
#define DL_STAB_ATTITUDE_angular_accel_r(_payload) pprzlink_get_DL_STAB_ATTITUDE_angular_accel_r(_payload)
#define DL_STAB_ATTITUDE_angular_accel_ref_p(_payload) pprzlink_get_DL_STAB_ATTITUDE_angular_accel_ref_p(_payload)
#define DL_STAB_ATTITUDE_angular_accel_ref_q(_payload) pprzlink_get_DL_STAB_ATTITUDE_angular_accel_ref_q(_payload)
#define DL_STAB_ATTITUDE_angular_accel_ref_r(_payload) pprzlink_get_DL_STAB_ATTITUDE_angular_accel_ref_r(_payload)
#define DL_STAB_ATTITUDE_nu_length(_payload) pprzlink_get_STAB_ATTITUDE_nu_length(_payload)
#define DL_STAB_ATTITUDE_nu(_payload) pprzlink_get_DL_STAB_ATTITUDE_nu(_payload)
#define DL_STAB_ATTITUDE_u_length(_payload) pprzlink_get_STAB_ATTITUDE_u_length(_payload)
#define DL_STAB_ATTITUDE_u(_payload) pprzlink_get_DL_STAB_ATTITUDE_u(_payload)



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _VAR_MESSAGES_telemetry_STAB_ATTITUDE_H_

