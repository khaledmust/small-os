#ifndef SOS_H_
#define SOS_H_

#include "../../utilities/std_types.h"

/**
 * @brief Describes the system status of the OS.
 * 
 */
typedef enum {
    SOS_STATUS_SUCCESS, SOS_STATUS_INVALID_STATE
}en_SOS_SYSTEM_STATUS_t;

/**
 * @brief Tasks configuration structure.
 * 
 */
typedef struct {
    uint8 pid; uint8 process_priority_level;
}st_SOS_TASK_t;

static st_SOS_TASK_t *g_ptr_sos_db;

/**
 * @brief 
 * 
 * @return en_SOS_SYSTEM_STATUS_t 
 */
en_SOS_SYSTEM_STATUS_t SOS_init(void);

/**
 * @brief De-allocates the created DB instance and points the DB pointer to NULL.
 * 
 * @return en_SOS_SYSTEM_STATUS_t 
 */
en_SOS_SYSTEM_STATUS_t SOS_deinit(void);

/**
 * @brief Adds a new task to the database.
 * 
 * @param ptr_st_SOS_DB Address of the tasks database.
 * @param pid Task's uniqie ID.
 * @param priority_level Task's priority level.
 */
void SOS_crateTask(st_SOS_TASK_t *ptr_st_SOS_DB, uint8 pid, uint8 priority_level);

/**
 * @brief Removes a task from the database.
 * 
 * @param ptr_st_SOS_DB Address of the tasks database.
 * @param pid Task's uniqie ID.
 */
void SOS_deleteTask(st_SOS_TASK_t *ptr_st_SOS_DB, uint8 pid);

/**
 * @brief Modifies the priority level of a task.
 * 
 * @param ptr_st_SOS_DB Address of the tasks database.
 * @param pid Task's uniqie ID.
 * @param priority_level Task's priority level.
 */
void SOS_modifyTask(st_SOS_TASK_t *ptr_st_SOS_DB, uint8 pid, uint8 priority_level);

/**
 * @brief Runs the small OS.
 * 
 * @param ptr_st_SOS_DB Address of the tasks database.
 */
void SOS_run(st_SOS_TASK_t *ptr_st_SOS_DB);

/**
 * @brief Halts the operation of the small OS.
 * 
 * @param ptr_st_SOS_DB Address of the tasks database.
 */
void SOS_disable(st_SOS_TASK_t *ptr_st_SOS_DB);

#endif /* SOS_H_ */