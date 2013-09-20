/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -v -a api_adaptor api.xml
 *
 * qdbusxml2cpp is Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef API_ADAPTOR_H_1379327883
#define API_ADAPTOR_H_1379327883

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
QT_BEGIN_NAMESPACE
class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;
QT_END_NAMESPACE

/*
 * Adaptor class for interface sdl.core.api
 */
class ApiAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "sdl.core.api")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"sdl.core.api\">\n"
"    <method name=\"send\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"json\"/>\n"
"    </method>\n"
"    <signal name=\"receive\">\n"
"      <arg type=\"s\" name=\"json\"/>\n"
"    </signal>\n"
"  </interface>\n"
        "")
public:
    ApiAdaptor(QObject *parent);
    virtual ~ApiAdaptor();

public: // PROPERTIES
public Q_SLOTS: // METHODS
    void send(const QString &json);
Q_SIGNALS: // SIGNALS
    void receive(const QString &json);
};

#endif
