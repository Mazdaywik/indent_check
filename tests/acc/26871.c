/* 1st semester, 2nd module, task 18
 * rangehd (fast)
 * binary indexed tree (Fenwik tree)
 * Time: O(I have no idea, no input limitation on update strings length were imposed)
 * */

//__   __                  _                         ___
//\ \ / /__  ___     _ __ | | ___  __ _ ___  ___    |_ _|
// \ V / _ \/ __|   | '_ \| |/ _ \/ _` / __|/ _ \    | |
//  | |  __/\__ \_  | |_) | |  __/ (_| \__ \  __/_   | |
//  |_|\___||___( ) | .__/|_|\___|\__,_|___/\___( ) |___|
//              |/  |_|                         |/
//                     _                                _            _
//__      ____ _ _ __ | |_   _ __ ___   ___  _ __ ___  | |_ __ _ ___| | _____
//\ \ /\ / / _` | '_ \| __| | '_ ` _ \ / _ \| '__/ _ \ | __/ _` / __| |/ / __|
// \ V  V / (_| | | | | |_  | | | | | | (_) | | |  __/ | || (_| \__ \   <\__ \
//  \_/\_/ \__,_|_| |_|\__| |_| |_| |_|\___/|_|  \___|  \__\__,_|___/_|\_\___/
//
//       _                 _
//  __ _| |__   ___  _   _| |_
// / _` | '_ \ / _ \| | | | __|
//| (_| | |_) | (_) | |_| | |_           Binary indexed tree
// \__,_|_.__/ \___/ \__,_|\__|
//


//                                            `".        .
//                                             .!`      ="
//                                              .|.    `!."`."= .!=
//                                     ``.     .!"|".`"!||&&&&|!|!`.
//                                      "|&|!=!||&&|&&&&|&|!!|=&|!&|==``
//                 "=`   "`.  ."=||!!||!="|=|&&|&|=!|&&&&|`.!&||&|||`!!!&&" ."=`
//                  |=!`."|&||&||!.        `!|" "|`"|&|!|||&&&||!|=.."``!=|&|&="..`==`
//                  !=!&&&&&=!!. `.          .=!!&."&&|||!|&&&|=|"  !"    `&="=|!|t=
//                "&&&|||!|||"                  "&|||&|==|&&=!|=.          `|&||=="!s=
//               !e. .`"===`                     """!|&|`=|!!=.             .=!="=|!=||
//              =l                                    .`===`                    .     &&.
//           ."e|.                                                                     "&&"
//          =&"                                                                          .&|
//          &"                                 .``.                                       !g
//         .T.                    ........`""""`.`"!........                              .G.
//         "&             ```"""""""````"`.         `"""""""""""""""""""""=.               &|
//        !t`             ``.                                                               |&.
//       |&                 .``"""==""==""""=="======"`"`````````...                         !N.
//      =m               .""`..                             .....`.`"==="=="""                n!
//      |!                                       .....                                        !t
//     .E`                               ."=====""`.``""===..                                 `T`
//     `E.                        .""==="`.                ."=="""""""=""""""""".             .T=
//     &=               `""""""""""`                                           ."              =t.
//    |&                                                                                        |&
//   .E`                                                            .""""""==..                 `R
//   .E`                .`""===========!=                        `!==.      ."=====.            `R
//   .E`          ."=!=="`                                                         "|"          `R.
//   =&          .".                                          "!.                    `="         r=
//   !!                                  "!.                `!`                                  |!
//   !"                                    ="               ".               `""""====.          !!
//   |"           =!!!!=""`..               `                       ...`=!|&SEM|!"!A&.           !|
//   &.            !S==!&ETASKSon|=`                            `|&&||EEPLEASEMO!`.&S.           "e
//   &`            `&`"`=ETASKSONSEge&!"                       `E=.".=EEPLEASEMOr"`|S.           ||
//   =|             `|&""ETASKSONs"```&T!                      "E="``=EEPLEASEMO|.."S.           R`
//   .&           =.  `!|&taskso&&|!|&&|.                      `|MNt&&&ePLEASEM&==!as`          .R
//   .E"          !a".&|"&&&||!===!&&|                          .`=|&&!`.`"""""=|&&&s!          !|
//    "G"          .!&mo&||&==!|||!"`                            .|!.."!&&|="""|!"".           |&
//     `E. "|.        .`!` """=======.        .`            .     ."|&|!==!!==!!!!!.          `T
//      &==|&.                                !&           `N         .`""==              `.!"`&
//      ||!`&.`=`                             &|           .N`                           "&|||"T`
//     "&= `|!!|"                           .!e.            |s.                          =|||&"||
//     =&"!&|"`|.                       ..=&&&"              &|`                         =|`!|&|&
//     `&|&= .=!  ..                .`"=||&!`                 `||.  .                   `|! =&|&|
//     =&&|`=|&! "|!             .`"`..!`.                      `&=..  .`.              !&|`=||||
//     !&&&|"|||!&|"           .``.   `=                          `t|    "="`          .&"!|||!!|`
//    .&&&&|||||&!&.        .`".      .&=                         .t=      .!!.        =!.!|&||&!.
//    .&|&&&||!"|"&`       `"`         `t`                       "n!         ==.       |"`&&&|n!
//    .&&&&=|!!|="|.     .``     "`     !!`.                   .!&=     .     ".      `|=&&|&|&
//    .=||&|||&&|||!!!=!".``..`"|||`"=="`"!=```"""`.   ..."==". !""=!!!!||=   `..``=..!||&&.|&!=".
//      .=|&&&&&|||||=`=||&&&|&||=!!==!!!!||!!||||="==!!|!!=!|!!|!="..``=&!.=&|!|&||=|&&||||&"."!`
//      .!&&|&&&|&&&|!!=====!||=|.!&|. ..``..... `"... .="```.``""=|tr&e==&|=&|=!!.|&||&&|&&&|||.
//       ."|&&|||||!. "!|&&!!|&=| .=e|                   ..    . .`.!r=` ."."!.!|".|||&|||&|`."!.
//         =&&||!|&"=|||!"|=&|!"|"!|=!!.                           `|". "=   ."&&! !!!!"|&&&"!=
//         =!|!|&&|&!|||=|||&|"||!&&!.`=!"                       `"`.`  |!"||!|&&&||=&!&|&"=!`
//        `|||&||l&|&&&&|&=|&||||=&||= ."|!!=.               .="````.  .|||||!&|!&||&|&|&&=
//        !="===!&&&&||&|!"|&||&|||!"|..!&".`""""""="""`"""""``  ..   .!|&!&&&&|&|&&&&||||.
//               =e&|!=||!||||!|&!|!`|=|&&" .      ....             .`|=&||&&&&|&&&!&&&&&"
//               `e||!||!""&!"||&!|||&&|"&`"&.."`      .`==`   =|  "&|=|&&&&&&&&|&&&&&&|&!=`
//               "&!|!|||&|&|&|&! "|&&&"=|!|||!|= .  `!!"`|!  =&|.!&&!||&&&!!&&|!||&&&&|&||!`
//               l= `||||&&&&||||!|||&|!|&&||. !|||=!=. .=&||!&&|!&|&|&|&|&&&&&&|&&|&|&``...
//              &=  .=||!=&&&|&|||&|&""&|!""& `&&&|"..=!="&&&&|&|&&&&|!|&&&|&&&||&&|!.s=
//             `p      ..`"=&!&&&!"=&=!!!.`=&!&&&&!!|&&!`"|&&!=||&&&&&!!|&&&&||..|&|. .o"
//             !|          .&|&&&|&||".`|!|&&&&&||&&&|||!"|||!=&&&&&&|=!&&&&&|!  ``    =&
//             &!           |||!"|&&|=!||||&&&&&&&=`!&="|=|&||&|&|!!&!=|&&=!||"        .N.
//            =&.           ..   `=|&&&!`""||&|||" .=&||&||||"||!..=&&&&&|=!=.         .n"
//          .r&.                   `|||!|&|==||&!=!|&||&&&=!|!=|=|&&&&|!=&!`            =s`
//         .t|                ."=   `=!!!!!||&&||&||&|&&&&&&&||&&|||=.  `"               `e!
//        .T!              `!=".                `"=!="`||`   =||` .    ..                 .g!
//       `&|             `|"                          `!.    .`        .&                  .e|
//      .!`              =                                              "`                  .!`
//

// _____ _     _       _                             _       _     _
//|_   _| |__ (_)___  (_)___   _ __ ___   ___   _ __(_) __ _| |__ | |_
//  | | | '_ \| / __| | / __| | '_ ` _ \ / _ \ | '__| |/ _` | '_ \| __|
//  | | | | | | \__ \ | \__ \ | | | | | |  __/ | |  | | (_| | | | | |_
//  |_| |_| |_|_|___/ |_|___/ |_| |_| |_|\___| |_|  |_|\__, |_| |_|\__|
//                                                     |___/
//
// _ __   _____      __
//| '_ \ / _ \ \ /\ / /
//| | | | (_) \ V  V /
//|_| |_|\___/ \_/\_/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

uint64_t max_lu(uint64_t a, uint64_t b){
    return (a > b) ? a : b;
}

int64_t max_ld(int64_t a, int64_t b){
    return (a > b) ? a : b;
}

bool weird_input(char* word, int m){
    int g = 0;
    bool sw = false;
    while (true){
        int ch = getc(stdin);
        if (ch == EOF){
            word[g] = 0;
            return false;
        } else if (ch <= 32){
            if (sw){
                word[g] = 0;
                break;
            }
        } else if (g + 1 < m){
            sw = true;
            word[g] = ch;
            g++;
        } else {
            assert(false);
            fprintf(stderr, "Input error\n");
            word[g] = 0;
            return false;
        }
    }
    return true;
}

typedef bool FenwikVal;
static const FenwikVal F_neutral = false;
FenwikVal F_combine(FenwikVal a, FenwikVal b){
    return a ^ b;
}

size_t FenwikF(size_t i){
    return i & (i + 1);
}

void Fenwik_add_to_single(FenwikVal* fenw, size_t n, size_t ind, FenwikVal val){
    assert(ind < n);
    size_t j = ind;
    while (j < n){
        fenw[j] = F_combine(fenw[j], val);
        j |= (j + 1);
    }
}

// [0:P)
FenwikVal Fenwik_get_sum_on_prefix(FenwikVal* fenw, size_t n, size_t P){
    FenwikVal res = F_neutral;
    while (P) {
        P--;
        res = F_combine(res, fenw[P]);
        P = FenwikF(P);
    }
    return res;
}

// [L:R)
FenwikVal Fenwik_get_sum_on_halfinterval(FenwikVal* fenw, size_t n, size_t l, size_t r){
    return Fenwik_get_sum_on_prefix(fenw, n, r) - Fenwik_get_sum_on_prefix(fenw, n, l);
}

int main(){
//    freopen("input.txt", "r", stdin);
    char* string = calloc(1e6+1, 1);
    weird_input(string, 1e6+1);
    size_t n = strlen(string);
    const char alph_start = 'a';
    const char alph_end = 'z';
    const int alph_sz = alph_end - alph_start + 1;
    char* arg_str = calloc(max_lu(4, n + 1), 1);
    FenwikVal* rupes[alph_sz];
    for (int c = 0; c < alph_sz; c++){
        rupes[c] = calloc(n, sizeof(FenwikVal));
    }
    for (size_t i = 0; i < n; i++){
        assert(alph_start <= string[i] && string[i] <= alph_end);
        int c = string[i] - alph_start;
        Fenwik_add_to_single(rupes[c], n, i, 1);
    }
    while (true){
        weird_input(arg_str, 4);
        if (strcmp(arg_str, "HD") == 0){
            // HD?
            uint64_t l, r;
            scanf("%lu %lu", &l, &r);
            assert(l <= r && r < n);
            r++;
            int odd_classes = 0;
            for (int c = 0; c < alph_sz; c++){
                odd_classes += (int)Fenwik_get_sum_on_halfinterval(rupes[c], n, l, r);
            }
            bool hyperdrom = ((r - l) % 2 == odd_classes);
            printf("%s\n", hyperdrom ? "YES" : "NO");
        } else if (strcmp(arg_str, "UPD") == 0){
            // UPD!
            uint64_t start;
            scanf("%lu", &start);
            weird_input(arg_str, n + 1);
            size_t m = strlen(arg_str);
            assert(start + m <= n);
            for (size_t i = 0; i < m; i++){
                if (arg_str[i] != string[i + start]){
                    Fenwik_add_to_single(rupes[string[i + start] - alph_start], n, i + start, true);
                    Fenwik_add_to_single(rupes[arg_str[i] - alph_start], n, i + start, true);
                    string[i + start] = arg_str[i];
                }
            }
        } else if (strcmp(arg_str, "END") == 0){
            break;
        } else {
            assert(false);
        }
    }
    for (int i = 0; i < alph_sz; i++){
        free(rupes[i]);
    }
    free(string);
    free(arg_str);
    return 0;
}