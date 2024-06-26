// SPDX-FileCopyrightText: 2022 Linus Jahn <lnj@kaidan.im>
//
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef QXMPPFILESHARE_H
#define QXMPPFILESHARE_H

#include "QXmppGlobal.h"

#include <any>
#include <functional>
#include <optional>

#include <QSharedDataPointer>

class QDomElement;
class QUrl;
class QXmlStreamWriter;
class QXmppFileSourcesAttachmentPrivate;
class QXmppFileSharePrivate;
class QXmppFileMetadata;
class QXmppHttpFileSource;
class QXmppEncryptedFileSource;

class QXMPP_EXPORT QXmppFileSourcesAttachment
{
public:
    QXmppFileSourcesAttachment();
    QXMPP_PRIVATE_DECLARE_RULE_OF_SIX(QXmppFileSourcesAttachment)

    const QString &id() const;
    void setId(const QString &);

    const QVector<QXmppHttpFileSource> &httpSources() const;
    void setHttpSources(const QVector<QXmppHttpFileSource> &newHttpSources);

    const QVector<QXmppEncryptedFileSource> &encryptedSources() const;
    void setEncryptedSources(const QVector<QXmppEncryptedFileSource> &newEncryptedSources);

private:
    friend class QXmppMessage;

    static std::optional<QXmppFileSourcesAttachment> fromDom(const QDomElement &el);
    void toXml(QXmlStreamWriter *writer) const;

    QSharedDataPointer<QXmppFileSourcesAttachmentPrivate> d;
};

class QXMPP_EXPORT QXmppFileShare
{
public:
    enum Disposition {
        Inline,
        Attachment,
    };

    QXmppFileShare();
    QXMPP_PRIVATE_DECLARE_RULE_OF_SIX(QXmppFileShare)

    Disposition disposition() const;
    void setDisposition(Disposition);

    const QString &id() const;
    void setId(const QString &);

    const QXmppFileMetadata &metadata() const;
    void setMetadata(const QXmppFileMetadata &);

    const QVector<QXmppHttpFileSource> &httpSources() const;
    void setHttpSources(const QVector<QXmppHttpFileSource> &newHttpSources);

    const QVector<QXmppEncryptedFileSource> &encryptedSources() const;
    void setEncryptedSourecs(const QVector<QXmppEncryptedFileSource> &newEncryptedSources);

    /// \cond
    bool parse(const QDomElement &el);
    void toXml(QXmlStreamWriter *writer) const;

protected:
    friend class QXmppFileSharingManager;
    friend class QXmppFileUpload;

    // Private, internally used API:
    void visitSources(std::function<bool(const std::any &)> &&visitor) const;
    void addSource(const std::any &source);
    /// \endcond

private:
    QSharedDataPointer<QXmppFileSharePrivate> d;
};

#endif  // QXMPPFILESHARE_H
