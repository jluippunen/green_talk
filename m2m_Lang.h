/*
 * Copyright 2017 Jukka Luippunen
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef M2M_LANG_H_
#define M2M_LANG_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct m2m_lang_word_s
{
    uint8_t type;   /* Word type */
    uint8_t affix;  /* m2m_lang_affix_t */
    uint8_t page;   /* Reserved for the future when several body tables are
                       needed */
    uint8_t body;   /* Word body according type */
} m2m_lang_word_t;

typedef struct m2m_lang_number_s
{
    uint8_t type;   /* M2M_LANG_NUMBER */
    uint8_t affix;  /* M2M_LANG_NONE or M2M_LANG_NEGATIVE */
    uint8_t msb;
    uint8_t lsb;
} m2m_lang_number_t;

typedef struct m2m_lang_string_s
{
    uint8_t type;         /* M2M_LANG_STRING */
    uint8_t string_type;  /* m2m_lang_string_type_t */
    uint8_t length_msb;
    uint8_t length_lsb;
} m2m_lang_string_t;

typedef union m2m_lang_item_u
{
    m2m_lang_word_t   word;
    m2m_lang_number_t number;
    m2m_lang_string_t string;
} m2m_lang_item_t;

typedef enum m2m_lang_type_e
{
    M2M_LANG_COMMAND = 0,
    M2M_LANG_VERB,
    M2M_LANG_NOUN,
    M2M_LANG_ADJ,
    M2M_LANG_NUMBER,
    M2M_LANG_STRING,
    M2M_LANG_TYPE_MAX
} m2m_lang_type_t;

typedef enum m2m_lang_affix_e
{
    M2M_LANG_NONE = 0,
    M2M_LANG_NEGATIVE,
    M2M_LANG_PLURAL,
    M2M_LANG_IMPERFECT,
    M2M_LANG_FUTURE,
    M2M_LANG_MORE,
    M2M_LANG_MOST,
    M2M_LANG_TO,
    M2M_LANG_FROM,
    M2M_LANG_IN,
    M2M_LANG_ON,
    M2M_LANG_UNDER,
    M2M_LANG_MY,
    M2M_LANG_YOURS,
    M2M_LANG_AFFIX_MAX
} m2m_lang_affix_t;

typedef enum m2m_lang_string_type_e
{
    M2M_LANG_STRING_UTF8 = 0,
    M2M_LANG_STRING_TYPE_MAX
} m2m_lang_string_type_t;

typedef enum m2m_lang_body_command_e
{
    M2M_LANG_COMMAND_BEGIN = 0,      /* Beginning of sentence */
    M2M_LANG_COMMAND_COMMA,          /* Separate two sentences */
    M2M_LANG_COMMAND_END,            /* Ending of sentence */
    M2M_LANG_COMMAND_QUESTION_END,   /* Ending of question sentence */
    M2M_LANG_BODY_COMMAND_MAX
} m2m_lang_body_command_t;

typedef enum m2m_lang_body_verb_e
{
    M2M_LANG_VERB_BE = 0,
    M2M_LANG_VERB_MOVE,
    M2M_LANG_VERB_TAKE,
    M2M_LANG_VERB_SEND,
    M2M_LANG_VERB_RECEIVE,
    M2M_LANG_BODY_VERB_MAX
} m2m_lang_body_verb_t;

typedef enum m2m_lang_body_noun_e
{
    M2M_LANG_NOUN_MACHINE = 0,
    M2M_LANG_NOUN_NAME,
    M2M_LANG_NOUN_ITEM,
    M2M_LANG_BODY_NOUN_MAX
} m2m_lang_body_noun_t;

typedef enum m2m_lang_body_adj_e
{
    M2M_LANG_ADJ_BIG = 0,
    M2M_LANG_ADJ_FAST,
    M2M_LANG_BODY_ADJ_MAX
} m2m_lang_body_adj_t;

#ifdef __cplusplus
}
#endif

#endif /* M2M_LANG_H_ */
