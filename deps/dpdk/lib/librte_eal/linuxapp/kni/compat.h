/*
 * Minimal wrappers to allow compiling kni on older kernels.
 */

#ifndef RHEL_RELEASE_VERSION
#define RHEL_RELEASE_VERSION(a, b) (((a) << 8) + (b))
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 39) && \
	(!(defined(RHEL_RELEASE_CODE) && \
	   RHEL_RELEASE_CODE >= RHEL_RELEASE_VERSION(6, 4)))

#define kstrtoul strict_strtoul

#endif /* < 2.6.39 */

#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,35)

#define sk_sleep(s) (s)->sk_sleep

#endif /* < 2.6.35 */
