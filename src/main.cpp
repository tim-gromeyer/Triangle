// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include <QGuiApplication>
#include <QIcon>
#include <QQmlApplicationEngine>
#include <QTranslator>

#include "triangle.h"

int main(int argc, char *argv[])
{
#ifdef Q_OS_ANDROID
    qputenv("QT_QUICK_CONTROLS_MATERIAL_THEME", QByteArray("Dark"));
#endif

    QGuiApplication app(argc, argv);
    app.setOrganizationName(u"Tim Gromeyer"_qs);
    app.setWindowIcon(QIcon(u"://triangle-svgrepo-com.svg"_qs));

    qmlRegisterType<Triangle>("Triangle", 1, 0, "Triangle");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/main.qml"_qs);
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    engine.addImportPath(QCoreApplication::applicationDirPath() + "/qml");
    engine.addImportPath(":/");

    engine.load(url);

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
