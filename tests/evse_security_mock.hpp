// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest

#ifndef OCPP_EVSE_SECURITY_MOCK_H
#define OCPP_EVSE_SECURITY_MOCK_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <ocpp/common/evse_security.hpp>

namespace ocpp {

class EvseSecurityMock : public EvseSecurity {
public:
    MOCK_METHOD(InstallCertificateResult, install_ca_certificate, (const std::string&, const CaCertificateType&),
                (override));
    MOCK_METHOD(DeleteCertificateResult, delete_certificate, (const ocpp::CertificateHashDataType&), (override));
    MOCK_METHOD(InstallCertificateResult, update_leaf_certificate,
                (const std::string&, const CertificateSigningUseEnum&), (override));
    MOCK_METHOD(InstallCertificateResult, verify_certificate, (const std::string&, const CertificateSigningUseEnum&),
                (override));
    MOCK_METHOD(std::vector<CertificateHashDataChain>, get_installed_certificates,
                (const std::vector<CertificateType>&), (override));
    MOCK_METHOD(std::vector<OCSPRequestData>, get_ocsp_request_data, (), (override));
    MOCK_METHOD(void, update_ocsp_cache, (const CertificateHashDataType&, const std::string&), (override));
    MOCK_METHOD(bool, is_ca_certificate_installed, (const CaCertificateType&), (override));
    MOCK_METHOD(std::string, generate_certificate_signing_request,
                (const CertificateSigningUseEnum&, const std::string&, const std::string&, const std::string&),
                (override));
    MOCK_METHOD(std::optional<KeyPair>, get_key_pair, (const CertificateSigningUseEnum&), (override));
    MOCK_METHOD(std::string, get_verify_file, (const CaCertificateType&), (override));
    MOCK_METHOD(int, get_leaf_expiry_days_count, (const CertificateSigningUseEnum&), (override));
};

} // namespace ocpp

#endif // OCPP_EVSE_SECURITY_MOCK_H
