/*
 *  New Multi-Task Scheduler Task ID
 *
 *  Source : D:\home\nomura-t\BM_Work\5thMix\lib_work\INCLUDE\TASKID.H
 *  Ref.   : C:\5thMix\work.5th\include\task_id.h (1998/04/08)
 *           C:\5thMix\work.5th\libfs\taskid.h    (1998/05/12)
 */
#ifndef MTS_TASKID_H
#define MTS_TASKID_H

#define MTSID_SYSTEM       0
#define MTSID_SOUND_INT    1
#define MTSID_SOUND_SET    2
#define MTSID_GAME         3
#define MTSID_SOUND_DUMMY  4
#define MTSID_SOUND_MAIN   5

/* 1998/04/08 */
#define MTSID_CD_READ      6
#define MTSID_MEMORY_CARD  7

/* 1998/05/12 */
#define MTSID_CD_SYSTEM    6
#define MTSID_MEMCARD      8

#define MTSID_IDLE         (MTS_NR_TASK - 1)

#endif // MTS_TASKID_H