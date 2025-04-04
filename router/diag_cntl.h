/*
 * Copyright (c) 2016-2018, The Linux Foundation. All rights reserved.
 * Copyright (c) 2016, Linaro Ltd.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef __DIAG_CNTL_H__
#define __DIAG_CNTL_H__

#include "peripheral.h"
#include "masks.h"

#define DIAG_ID_VERSION_1	1
#define DIAG_ID_VERSION_2	2
#define DIAG_ID_VERSION_3	3
#define DIAG_ID_APPS	1

#define DIAG_MAX_REQ_SIZE	(16 * 1024)
#define DIAG_MAX_RSP_SIZE	(16 * 1024)

struct diag_id_info
{
	uint8_t diag_id;
	uint8_t process_name_len;
	char process_name[];
};

struct diag_id_tbl_t {
	struct list_head node;
	uint8_t diag_id_info_len;
	struct diag_id_info diagid_info;
};

int diag_cntl_recv(struct peripheral *perif, const void *buf, size_t len);
void diag_cntl_send_log_mask(struct peripheral *peripheral, uint32_t equip_id);
void diag_cntl_send_msg_mask(struct peripheral *peripheral, struct diag_ssid_range_t *range);
void diag_cntl_send_event_mask(struct peripheral *peripheral);
void diag_cntl_close(struct peripheral *peripheral);

void diag_cntl_send_masks(struct peripheral *peripheral);

void diag_cntl_set_diag_mode(struct peripheral *perif, bool real_time);
void diag_cntl_set_buffering_mode(struct peripheral *perif, int mode);

struct list_head *diag_get_diag_ids_head(void);
int diag_cntl_send_passthru_control_pkt(struct diag_hw_accel_cmd_req_t *req_params);

#endif
