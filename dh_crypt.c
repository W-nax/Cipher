/// \file dh_crypt.c
/// \author Axel Delas
/// \date October 2020
/// \brief Beacons treatment depending on user parameters choice or error message

#include "dh_crypt.h"
#include "dh_bal.h"

void help_message(void) {
/// \brief Error message to print
  printf("Usage : dh_crypt [OPTIONS] SRC_FILENAME DST_FILENAME KEY METHOD\n");
  printf("Crypt or decrypt message file using xor or cbc method.\n");
  printf("\n  -i filename\t\tuncrypted or crypted message source\n");
  printf("  -o filename\t\tuncrypted or crypted message destination\n");
  printf("  -k key\t\tcrypt key\n");
  printf("  -m [init_vec]\t\tcrypt method : xor or cbc-crypt or cbc-uncrypt with the initialisation vector for cbc method\n");
}

int main(int argc, char **argv) {
/// \brief Beacons treatment with user parameters
/// \details Looking and save beacons informations
/// \param[in] argc Number of parameters
/// \param[in] argv Table contening parameters informations
/// \returns Code 0
  char *src_filename=NULL, *dst_filename=NULL, *k=NULL, *init_vec=NULL;

  if (has_h_beacon(argc, argv))
    help_message();
  else if (has_xor_arg(argc, argv)) {
    for (int i=1; i<argc; i++) {
      if (is_i_beacon(i, argv)) {
        src_filename=calloc(strlen(argv[i+1]), 1);
        strcpy(src_filename, argv[i+1]);
      }
      else if (is_o_beacon(i, argv)) {
        dst_filename=calloc(strlen(argv[i+1]), 1);
        strcpy(dst_filename, argv[i+1]);
      }
      else if (is_k_beacon(i, argv)) {
        k=calloc(strlen(argv[i+1]), 1);
        strcpy(k, argv[i+1]);
      }
    }
    if (src_filename==NULL || dst_filename==NULL || k==NULL)
      printf("Usage : dh_crypt -h\n");
    else if (fopen(src_filename, "r")==NULL)
      printf("Source file does not exist or is not reading accessible\n");
    else {
      xor(src_filename, dst_filename, k);
      free(src_filename); free(dst_filename); free(k);
    }
  }
  else if (has_cbc_crypt_arg(argc, argv)) {
    for (int i=1; i<argc; i++) {
      if (is_i_beacon(i, argv)) {
        src_filename=calloc(strlen(argv[i+1]), 1);
        strcpy(src_filename, argv[i+1]);
      }
      else if (is_o_beacon(i, argv)) {
        dst_filename=calloc(strlen(argv[i+1]), 1);
        strcpy(dst_filename, argv[i+1]);
      }
      else if (is_k_beacon(i, argv)) {
        k=calloc(strlen(argv[i+1]), 1);
        strcpy(k, argv[i+1]);
      }
      else if (is_m_beacon(i, argv)) {
        init_vec=calloc(strlen(argv[i+1]), 1);
        strcpy(init_vec, argv[i+2]);
      }
    }
    if (src_filename==NULL || dst_filename==NULL || k==NULL || strlen(init_vec)!=16)
      printf("Usage : dh_crypt -h\n");
    else if (fopen(src_filename, "r")==NULL)
      printf("Source file does not exist or is not reading accessible\n");
    else {
      cbc_crypt(src_filename, dst_filename, k, init_vec);
      free(src_filename); free(dst_filename); free(k); free(init_vec);
    }
  }
  else if (has_cbc_uncrypt_arg(argc, argv)) {
    for (int i=1; i<argc; i++) {
      if (is_i_beacon(i, argv)) {
        src_filename=calloc(strlen(argv[i+1]), 1);
        strcpy(src_filename, argv[i+1]);
      }
      else if (is_o_beacon(i, argv)) {
        dst_filename=calloc(strlen(argv[i+1]), 1);
        strcpy(dst_filename, argv[i+1]);
      }
      else if (is_k_beacon(i, argv)) {
        k=calloc(strlen(argv[i+1]), 1);
        strcpy(k, argv[i+1]);
      }
      else if (is_m_beacon(i, argv)) {
        init_vec=calloc(strlen(argv[i+1]), 1);
        strcpy(init_vec, argv[i+2]);
      }
    }
    if (src_filename==NULL || dst_filename==NULL || k==NULL || strlen(init_vec)!=16)
      printf("Usage : dh_crypt -h\n");
    else if (fopen(src_filename, "r")==NULL)
      printf("Source file does not exist or is not reading accessible\n");
    else {
      cbc_uncrypt(src_filename, dst_filename, k, init_vec);
      free(src_filename); free(dst_filename); free(k); free(init_vec);
    }
  }
  else
    printf("Usage : dh_crypt -h\n");
  return 0;
}
