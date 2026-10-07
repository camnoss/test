/*
 * Registers the opcodes of fm_test with the Connection Manager.
 * conf/pin.conf.d/fm_test.conf points the CM at this table.
 *
 * To add an opcode: define its number in include/test_ops.h,
 * add its handler under src/ops/ and its logic under src/logic/, then add a
 * line to this table.
 */
#include <stdio.h>

#include "pcm.h"
#include "cm_fm.h"

#include "test_ops.h"

/* clang-format off */
struct cm_fm_config fm_test_config[] = {
	/* opcode, handler function name (the CM looks it up by name) */
	{ NERV_OP_TEST_TEST,	"op_test_test" },
	{ 0,	(char *)0 }
};
/* clang-format on */

void *
fm_test_config_func(void)
{
	return ((void *)(fm_test_config));
}
