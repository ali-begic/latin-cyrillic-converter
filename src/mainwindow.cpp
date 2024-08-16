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
#include "ui_mainwindow.h"

#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QString statusBarMessage = "Latin - Cyrillic Converter - by AliTech Works v1.0";
    ui->statusBar->setSizeGripEnabled(false);
    ui->statusBar->setStyleSheet("border-top: 1px outset grey;");
    ui->statusBar->showMessage(statusBarMessage);

    ui->main_frame->setStyleSheet("border: none");

    ui->input_textEdit->setStyleSheet("border: 1px solid black");
    ui->output_textEdit->setStyleSheet("border: 1px solid black; background-color: white; color: black");

    ui->output_textEdit->setReadOnly(true);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_convert_pushButton_clicked() {
    QString inputText = ui->input_textEdit->toPlainText();

    if (ui->typeOfConversion_comboBox->currentText() == "Latin to Cyrillic") {
        ui->output_textEdit->setPlainText(convertLatinToCyrillic(inputText));
    } else if (ui->typeOfConversion_comboBox->currentText() == "Cyrillic to Latin") {
        ui->output_textEdit->setPlainText(convertCyrillicToLatin(convertCyrillicToLatin(inputText)));
    }
}

void MainWindow::on_openFromFile_pushButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(
        this, tr("Open File"), "",
        tr("Text Files (*.txt);;CSV Files (*.csv);;Log Files (*.log);;XML Files (*.xml);;HTML Files (*.html *.htm);;"
           "JSON Files (*.json);;YAML Files (*.yaml *.yml);;All Files (*)")
    );

    if (fileName.isEmpty())
        return;

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, tr("Error"), tr("Cannot open file for reading:\n%1").arg(file.errorString()));

        return;
    }

    QTextStream in(&file);

    QString fileContent = in.readAll();

    file.close();

    if (ui->typeOfConversion_comboBox->currentText() == "Latin to Cyrillic") {
        ui->input_textEdit->setText(fileContent);
        ui->output_textEdit->setText(convertLatinToCyrillic(fileContent));
    } else if (ui->typeOfConversion_comboBox->currentText() == "Cyrillic to Latin") {
        ui->input_textEdit->setText(fileContent);
        ui->output_textEdit->setText(convertCyrillicToLatin(fileContent));
    }
}

void MainWindow::on_saveToFile_pushButton_clicked() {
    QString content = ui->output_textEdit->toPlainText();

    if (!content.isEmpty()) {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);;All Files (*)"));

        if (fileName.isEmpty())
            return;

        QFile file(fileName);

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::critical(this, tr("Error"), tr("Cannot open file for writing:\n%1").arg(file.errorString()));

            return;
        }

        QTextStream out(&file);

        out << content;

        file.close();
    } else {
        QMessageBox::warning(this, tr("Warning"), tr("There is no content to save."));
    }
}

void MainWindow::on_clear_pushButton_clicked() {
    ui->input_textEdit->clear();
    ui->output_textEdit->clear();
}
