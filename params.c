#include "main.h"

/**
 * init_params - Initializes parameters struct with default values.
 * @params: Pointer to parameters struct.
 * @ap: Argument pointer.
 *
 * This function sets all fields of the parameters struct to their default values
 * and prepares it for use in formatting a new output string.
 */
void init_params(params_t *params, va_list ap)
{
  // Initialize all fields of the params struct to their default values
  params->unsign = 0;
  params->plus_flag = 0;
  params->space_flag = 0;
  params->hashtag_flag = 0;
  params->zero_flag = 0;
  params->minus_flag = 0;
  params->width = 0;
  params->precision = UINT_MAX;
  params->h_modifier = 0;
  params->l_modifier = 0;

  // Consume the argument pointer to avoid unused parameter warning
  (void)ap;
}

