#include <stdio.h>
#include <oqs/oqs.h>

int tpm2_testliboqs(void) {
    OQS_STATUS rc;
    OQS_KEM *kem = NULL;

    rc = OQS_SUCCESS;

    printf("Testing liboqs integration...\n");

    kem = OQS_KEM_new(OQS_KEM_alg_kyber_768);
    if (kem == NULL) {
        fprintf(stderr, "OQS_KEM_new failed\n");
        return 1;
    }

    printf("liboqs initialized with algorithm %s\n", kem->method_name);

    OQS_MEM_secure_free(kem, sizeof(kem));

    return rc == OQS_SUCCESS ? 0 : 1;
}