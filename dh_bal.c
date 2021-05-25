/// \file dh_bal.c
/// \author Axel Delas
/// \date October 2020
/// \brief Pointing beacons functions

#include "dh_bal.h"

bool has_h_beacon(int argc, char **argv) {
/// \brief Verification if -h (-help) beacon appear
/// \param[in] argc Number of parameters
/// \param[in] argv Table containing user informations
/// \returns Boolean True or False
  int i=0;
  while (i<argc) {
    if (!strcmp(argv[i], "-h"))
      return true;
    i++;
  }
  return false;
}

bool has_o_beacon(int argc, char **argv) {
/// \brief Verification if -o (-outfile) beacon appear
/// \param[in] argc Number of parameters
/// \param[in] argv Table containing user informations
/// \returns Boolean True or False
  int i=0;
  while (i<argc) {
    if (!strcmp(argv[i], "-o"))
      return true;
    i++;
  }
  return false;
}

bool has_xor_arg(int argc, char **argv) {
/// \brief Verification if xor argument appear
/// \param[in] argc Number of parameters
/// \param[in] argv Table containing user informations
/// \returns Boolean True or False
  int i=0;
  while (i<argc) {
    if (!strcmp(argv[i], "xor"))
      return true;
    i++;
  }
  return false;
}

bool has_cbc_crypt_arg(int argc, char **argv) {
/// \brief Verification if cbc-crypt argument appear
/// \param[in] argc Number of parameters
/// \param[in] argv Table containing user informations
/// \returns Boolean True or False
  int i=0;
  while (i<argc) {
    if (!strcmp(argv[i], "cbc-crypt"))
      return true;
    i++;
  }
  return false;
}

bool has_cbc_uncrypt_arg(int argc, char **argv) {
/// \brief Verification if cbc-uncrypt argument appear
/// \param[in] argc Number of parameters
/// \param[in] argv Table containing user informations
/// \returns Boolean True or False
  int i=0;
  while (i<argc) {
    if (!strcmp(argv[i], "cbc-uncrypt"))
      return true;
    i++;
  }
  return false;
}

bool has_c1_arg(int argc, char **argv) {
/// \brief Verification if c1 argument appear
/// \param[in] argc Number of parameters
/// \param[in] argv Table containing user informations
/// \returns Boolean True or False
  int i=0;
  while (i<argc) {
    if (!strcmp(argv[i], "c1"))
      return true;
    i++;
  }
  return false;
}

bool has_all_arg(int argc, char **argv) {
/// \brief Verification if all argument appear
/// \param[in] argc Number of parameters
/// \param[in] argv Table containing user informations
/// \returns Boolean True or False
  int i=0;
  while (i<argc) {
    if (!strcmp(argv[i], "all"))
      return true;
    i++;
  }
  return false;
}

bool is_o_beacon(int i, char **argv) {
/// \brief -o (-outfile) beacon pointing
/// \param[in] i Parameter index to verificate
/// \param[in] argv Table containing user informations
/// \returns Boolean True or False
  if (!strcmp(argv[i], "-o"))
    return true;
  return false;
}

bool is_i_beacon(int i, char **argv) {
/// \brief -i (-infile) beacon pointing
/// \param[in] i Parameter index to verificate
/// \param[in] argv Table containing user informations
/// \returns Boolean True or False
  if (!strcmp(argv[i], "-i"))
    return true;
  return false;
}

bool is_k_beacon(int i, char **argv) {
/// \brief -k (-key) beacon pointing
/// \param[in] i Parameter index to verificate
/// \param[in] argv Table containing user informations
/// \returns Boolean True or False
  if (!strcmp(argv[i], "-k"))
    return true;
  return false;
}

bool is_m_beacon(int i, char **argv) {
/// \brief -m (-method) beacon pointing
/// \param[in] i Parameter index to verificate
/// \param[in] argv Table containing user informations
/// \returns Boolean True or False
  if (!strcmp(argv[i], "-m"))
    return true;
  return false;
}
