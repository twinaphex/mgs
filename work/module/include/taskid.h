/*
 * New Multi-Task Scheduler for PSX
 * Task ID Definition
 *
 * ref. beatmania APPEND 5thMIX
 *  1998.04.08 : work.5th/include/task_id.h
 *  1998.05.12 : work.5th/libfs/taskid.h
 */
#ifndef INC_TASKID_H
#define INC_TASKID_H

#define MTSID_SYSTEM       0
#define MTSID_SOUND_INT    1
#define MTSID_SOUND_SET    2
#define MTSID_GAME         3
#define MTSID_SOUND_DUMMY  4
#define MTSID_SOUND_MAIN   5

/* 1998.04.08 */
#define MTSID_CD_READ      6
#define MTSID_MEMORY_CARD  7

/* 1998.05.12 */
#define MTSID_CD_SYSTEM    6
#define MTSID_MEMCARD      8

#define MTSID_IDLE         (MTS_NR_TASK - 1)

#endif /* END OF FILE */

/* -*- indent-tabs-mode: t; tab-width: 4; mode: c; -*- */
/* vim: set noet ts=4 sw=4 ft=c ff=dos fenc=euc-jp : */
