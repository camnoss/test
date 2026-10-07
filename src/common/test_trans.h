/*
 * Transaction helpers for the opcodes of fm_test.
 *
 * BRM has no nested transactions. An opcode opens one only if its caller has
 * not, and only the opcode that opened it commits or aborts it.
 */
#ifndef TEST_TRANS_H
#define TEST_TRANS_H

#include "pcm.h"

/*
 * Opens a transaction on the database of the input POID, unless one is
 * already open. Returns LOCAL_TRANS_OPEN_SUCCESS if it opened one.
 */
int32 test_trans_open(pcm_context_t *ctxp, int32 flags, pin_flist_t *i_flistp, pin_errbuf_t *ebufp);

/*
 * Commits the transaction if test_trans_open opened it, or aborts
 * it if ebufp holds an error. Does nothing otherwise.
 */
void test_trans_close(pcm_context_t *ctxp, int32 local, pin_errbuf_t *ebufp);

#endif /* TEST_TRANS_H */
