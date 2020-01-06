/*
 * Copyright (C) 2008-2020 The QXmpp developers
 *
 * Author:
 *  Jeremy Lainé
 *
 * Source:
 *  https://github.com/qxmpp-project/qxmpp
 *
 * This file is a part of QXmpp library.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 */

#ifndef QXMPPSTREAMFEATURES_H
#define QXMPPSTREAMFEATURES_H

#include "QXmppStanza.h"

class QXMPP_EXPORT QXmppStreamFeatures : public QXmppStanza
{
public:
    QXmppStreamFeatures();

    enum Mode {
        Disabled = 0,
        Enabled,
        Required
    };

    Mode bindMode() const;
    void setBindMode(Mode mode);

    Mode sessionMode() const;
    void setSessionMode(Mode mode);

    Mode nonSaslAuthMode() const;
    void setNonSaslAuthMode(Mode mode);

    QStringList authMechanisms() const;
    void setAuthMechanisms(const QStringList &mechanisms);

    QStringList compressionMethods() const;
    void setCompressionMethods(const QStringList &methods);

    Mode tlsMode() const;
    void setTlsMode(Mode mode);

    /// Returns the mode (disabled, enabled or required) for XEP-0198: Stream
    /// Management
    Mode streamManagementMode() const;

    /// Sets the mode for XEP-0198: Stream Management
    ///
    /// \pa mode The mode to set.
    void setStreamManagementMode(Mode mode);

    /// Returns the mode for XEP-0352: Client State Indication
    Mode clientStateIndicationMode() const;

    /// Sets the mode for XEP-0352: Client State Indication
    ///
    /// \pa mode The mode to set.
    void setClientStateIndicationMode(Mode mode);

    /// Returns the mode for XEP-0077: In-Band Registration
    ///
    /// \since QXmpp 1.1
    Mode registerMode() const;

    /// Sets the mode for XEP-0077: In-Band Registration
    ///
    /// \pa mode The mode to set.
    ///
    /// \since QXmpp 1.1
    void setRegisterMode(const Mode &registerMode);

    /// \cond
    void parse(const QDomElement &element) override;
    void toXml(QXmlStreamWriter *writer) const override;
    /// \endcond

    static bool isStreamFeatures(const QDomElement &element);

private:
    Mode m_bindMode;
    Mode m_sessionMode;
    Mode m_nonSaslAuthMode;
    Mode m_tlsMode;
    Mode m_streamManagementMode;
    Mode m_csiMode;
    Mode m_registerMode;
    QStringList m_authMechanisms;
    QStringList m_compressionMethods;
};

#endif
