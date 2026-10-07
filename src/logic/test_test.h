/*
 * Flist logic of NERV_OP_TEST_TEST.
 *
 * No PCM calls here, so the unit tests run it without a CM. The handler in
 * src/ops/ does the PCM work. Every function returns right away if ebufp
 * already holds an error, and the caller owns any flist it returns.
 */
#ifndef TEST_TEST_H
#define TEST_TEST_H

#include "pcm.h"

/* Sets ebufp if the input flist is not valid. */
void test_test_validate(pin_flist_t *i_flistp, pin_errbuf_t *ebufp);

/* Builds the PCM_OP_READ_FLDS input for the account. */
pin_flist_t *test_test_read_flist(pin_flist_t *i_flistp, pin_errbuf_t *ebufp);

/* Builds the opcode output from the PCM_OP_READ_FLDS result. */
pin_flist_t *test_test_output(pin_flist_t *read_flistp, pin_errbuf_t *ebufp);

#endif /* TEST_TEST_H */
