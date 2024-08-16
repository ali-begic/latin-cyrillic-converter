/*
 * Copyright 2024 AliTech Works
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

#include "mainwindow.h"

#include <QString>
#include <QMap>

QString MainWindow::convertLatinToCyrillic(const QString &input) {
    QMap<QString, QString> latinToCyrillic;

    latinToCyrillic["A"] = "А";  latinToCyrillic["a"] = "а";
    latinToCyrillic["B"] = "Б";  latinToCyrillic["b"] = "б";
    latinToCyrillic["V"] = "В";  latinToCyrillic["v"] = "в";
    latinToCyrillic["G"] = "Г";  latinToCyrillic["g"] = "г";
    latinToCyrillic["D"] = "Д";  latinToCyrillic["d"] = "д";
    latinToCyrillic["Đ"] = "Ђ";  latinToCyrillic["đ"] = "ђ";
    latinToCyrillic["E"] = "Е";  latinToCyrillic["e"] = "е";
    latinToCyrillic["Ž"] = "Ж";  latinToCyrillic["ž"] = "ж";
    latinToCyrillic["Z"] = "З";  latinToCyrillic["z"] = "з";
    latinToCyrillic["I"] = "И";  latinToCyrillic["i"] = "и";
    latinToCyrillic["J"] = "Ј";  latinToCyrillic["j"] = "ј";
    latinToCyrillic["K"] = "К";  latinToCyrillic["k"] = "к";
    latinToCyrillic["L"] = "Л";  latinToCyrillic["l"] = "л";
    latinToCyrillic["Lj"] = "Љ"; latinToCyrillic["lj"] = "љ";
    latinToCyrillic["M"] = "М";  latinToCyrillic["m"] = "м";
    latinToCyrillic["N"] = "Н";  latinToCyrillic["n"] = "н";
    latinToCyrillic["Nj"] = "Њ"; latinToCyrillic["nj"] = "њ";
    latinToCyrillic["O"] = "О";  latinToCyrillic["o"] = "о";
    latinToCyrillic["P"] = "П";  latinToCyrillic["p"] = "п";
    latinToCyrillic["R"] = "Р";  latinToCyrillic["r"] = "р";
    latinToCyrillic["S"] = "С";  latinToCyrillic["s"] = "с";
    latinToCyrillic["T"] = "Т";  latinToCyrillic["t"] = "т";
    latinToCyrillic["Ć"] = "Ћ";  latinToCyrillic["ć"] = "ћ";
    latinToCyrillic["U"] = "У";  latinToCyrillic["u"] = "у";
    latinToCyrillic["F"] = "Ф";  latinToCyrillic["f"] = "ф";
    latinToCyrillic["H"] = "Х";  latinToCyrillic["h"] = "х";
    latinToCyrillic["C"] = "Ц";  latinToCyrillic["c"] = "ц";
    latinToCyrillic["Č"] = "Ч";  latinToCyrillic["č"] = "ч";
    latinToCyrillic["Dž"] = "Џ"; latinToCyrillic["dž"] = "џ";
    latinToCyrillic["Š"] = "Ш";  latinToCyrillic["š"] = "ш";

    QString result;

    int i = 0;

    while (i < input.length()) {
        QString twoChar = input.mid(i, 2);
        QString oneChar = input.mid(i, 1);

        if (latinToCyrillic.contains(twoChar)) {
            result += latinToCyrillic[twoChar];

            i += 2;
        } else if (latinToCyrillic.contains(oneChar)) {
            result += latinToCyrillic[oneChar];

            i += 1;
        } else {
            result += oneChar;

            i += 1;
        }
    }

    return result;
}
