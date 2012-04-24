#ifndef IUTIL_H
#define IUTIL_H

// libsolv
#include "solv/queue.h"
#include "solv/repo.h"
#include "solv/rules.h"
#include "solv/transaction.h"

// hawkey
#include "packagelist.h"
#include "sack.h"

#define CHKSUM_BYTES 32

// log levels (see also SOLV_ERROR etc. in <solv/pool.h>)
#define HY_LL_INFO  (1 << 20)
#define HY_LL_ERROR (1 << 21)

#define HY_LOG_INFO(...) sack_log(sack, HY_LL_INFO, __VA_ARGS__)
#define HY_LOG_ERROR(...) sack_log(sack, HY_LL_ERROR, __VA_ARGS__)

/* crypto utils */
int checksum_cmp(const unsigned char *cs1, const unsigned char *cs2);
int checksum_fp(unsigned char *out, FILE *fp);
int checksum_read(unsigned char *csout, FILE *fp);
int checksum_stat(unsigned char *out, FILE *fp);
int checksum_write(const unsigned char *cs, FILE *fp);
void checksum_dump(const unsigned char *cs);

/* filesystem utils */
int is_readable_rpm(const char *fn);
int mkcachedir(const char *path);
char *this_username(void);

/* misc utils */
unsigned count_nullt_array(const char **a);

/* libsolv utils */
void repo_internalize_trigger(Repo *r);
Transaction *job2transaction(HySack sack, Queue *job, Queue *errors);
void queue2plist(HySack sack, Queue *q, HyPackageList plist);
char *problemruleinfo2str(Pool *pool, SolverRuleinfo type, Id source, Id target, Id dep);
Id what_updates(Pool *pool, Id p);

#endif
