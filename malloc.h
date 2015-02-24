/* EFI malloc support library */

#ifndef __EFI_MALLOC_H__
#define __EFI_MALLOC_H__

/**
 * allocate_pool - Allocate pool memory
 * @type: the type of pool to allocate
 * @size: number of bytes to allocate from pool of @type
 * @buffer: used to return the address of allocated memory
 *
 * Allocate memory from pool of @type. If the pool needs more memory
 * pages are allocated from EfiConventionalMemory in order to grow the
 * pool.
 *
 * All allocations are eight-byte aligned.
 */
static inline EFI_STATUS
allocate_pool(EFI_MEMORY_TYPE type, UINTN size, void **buffer)
{
	return uefi_call_wrapper(boot->AllocatePool, 3, type, size, buffer);
}

/**
 * free_pool - Return pool memory to the system
 * @buffer: the buffer to free
 *
 * Return @buffer to the system. The returned memory is marked as
 * EfiConventionalMemory.
 */
static inline EFI_STATUS free_pool(void *buffer)
{
	return uefi_call_wrapper(boot->FreePool, 1, buffer);
}

/* Functions */
void *malloc(UINTN size);
void free(void *buffer);

#endif /* __EFI_MALLOC_H__ */
