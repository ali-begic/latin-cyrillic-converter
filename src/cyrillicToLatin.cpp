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

QString MainWindow::convertCyrillicToLatin(const QString &input) {
    QMap<QString, QString> cyrillicToLatin;

    cyrillicToLatin["А"] = "A";  cyrillicToLatin["а"] = "a";
    cyrillicToLatin["Б"] = "B";  cyrillicToLatin["б"] = "b";
    cyrillicToLatin["В"] = "V";  cyrillicToLatin["в"] = "v";
    cyrillicToLatin["Г"] = "G";  cyrillicToLatin["г"] = "g";
    cyrillicToLatin["Д"] = "D";  cyrillicToLatin["д"] = "d";
    cyrillicToLatin["Ђ"] = "Đ";  cyrillicToLatin["ђ"] = "đ";
    cyrillicToLatin["Е"] = "E";  cyrillicToLatin["е"] = "e";
    cyrillicToLatin["Ж"] = "Ž";  cyrillicToLatin["ж"] = "ž";
    cyrillicToLatin["З"] = "Z";  cyrillicToLatin["з"] = "z";
    cyrillicToLatin["И"] = "I";  cyrillicToLatin["и"] = "i";
    cyrillicToLatin["Ј"] = "J";  cyrillicToLatin["ј"] = "j";
    cyrillicToLatin["К"] = "K";  cyrillicToLatin["к"] = "k";
    cyrillicToLatin["Л"] = "L";  cyrillicToLatin["л"] = "l";
    cyrillicToLatin["Љ"] = "Lj"; cyrillicToLatin["љ"] = "lj";
    cyrillicToLatin["М"] = "M";  cyrillicToLatin["м"] = "m";
    cyrillicToLatin["Н"] = "N";  cyrillicToLatin["н"] = "n";
    cyrillicToLatin["Њ"] = "Nj"; cyrillicToLatin["њ"] = "nj";
    cyrillicToLatin["О"] = "O";  cyrillicToLatin["о"] = "o";
    cyrillicToLatin["П"] = "P";  cyrillicToLatin["п"] = "p";
    cyrillicToLatin["Р"] = "R";  cyrillicToLatin["р"] = "r";
    cyrillicToLatin["С"] = "S";  cyrillicToLatin["с"] = "s";
    cyrillicToLatin["Т"] = "T";  cyrillicToLatin["т"] = "t";
    cyrillicToLatin["Ћ"] = "Ć";  cyrillicToLatin["ћ"] = "ć";
    cyrillicToLatin["У"] = "U";  cyrillicToLatin["у"] = "u";
    cyrillicToLatin["Ф"] = "F";  cyrillicToLatin["ф"] = "f";
    cyrillicToLatin["Х"] = "H";  cyrillicToLatin["х"] = "h";
    cyrillicToLatin["Ц"] = "C";  cyrillicToLatin["ц"] = "c";
    cyrillicToLatin["Ч"] = "Č";  cyrillicToLatin["ч"] = "č";
    cyrillicToLatin["Џ"] = "Dž"; cyrillicToLatin["џ"] = "dž";
    cyrillicToLatin["Ш"] = "Š";  cyrillicToLatin["ш"] = "š";

    QString result;

    int i = 0;

    while (i < input.length()) {
        QString twoChar = input.mid(i, 2);
        QString oneChar = input.mid(i, 1);

        if (cyrillicToLatin.contains(twoChar)) {
            result += cyrillicToLatin[twoChar];

            i += 2;
        } else if (cyrillicToLatin.contains(oneChar)) {
            result += cyrillicToLatin[oneChar];

            i += 1;
        } else {
            result += oneChar;

            i += 1;
        }
    }

    return result;
}
