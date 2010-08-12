/*
 *  Copyright (C) 2010 Felix Geyer <debfx@fobos.de>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 or (at your option)
 *  version 3 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KEEPASSX_GROUP_H
#define KEEPASSX_GROUP_H

#include <QtGui/QImage>

#include "Entry.h"
#include "TimeInfo.h"
#include "Uuid.h"

class Database;

class Group : public QObject
{
    Q_OBJECT

public:
    Group();
    Uuid uuid() const;
    QString name() const;
    QString notes() const;
    QImage icon() const;
    TimeInfo timeInfo() const;
    bool isExpanded() const;
    QString defaultAutoTypeSequence() const;
    Entry* lastTopVisibleEntry() const;

    void setUuid(const Uuid& uuid);
    void setName(const QString& name);
    void setNotes(const QString& notes);
    void setIcon(int iconNumber);
    void setIcon(const Uuid& uuid);
    void setTimeInfo(const TimeInfo& timeInfo);
    void setExpanded(bool expanded);
    void setDefaultAutoTypeSequence(const QString& sequence);
    void setLastTopVisibleEntry(Entry* entry);

    void setParent(Group* parent);
    void setParent(Database* db);

    QList<Group*> children() const;
    QList<Entry*> entries() const;
    void addEntry(Entry* entry);
    void removeEntry(Entry* entry);

private:
    Database* m_db;
    Uuid m_uuid;
    QString m_name;
    QString m_notes;
    int m_iconNumber;
    Uuid m_customIcon;
    TimeInfo m_timeInfo;
    bool m_isExpanded;
    QString m_defaultAutoTypeSequence;
    Entry* m_lastTopVisibleEntry;
    QList<Group*> m_children;
    QList<Entry*> m_entries;

    Group* m_parent;
};

#endif // KEEPASSX_GROUP_H
