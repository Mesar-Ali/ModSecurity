/*
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 - 2021 Trustwave Holdings, Inc. (http://www.trustwave.com/)
 *
 * You may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * If any of the files related to licensing are missing or if you have any
 * other questions related to licensing please contact Trustwave Holdings, Inc.
 * directly using the email address security@modsecurity.org.
 *
 */

#ifndef SRC_OPERATORS_CONTAINS_WORD_H_
#define SRC_OPERATORS_CONTAINS_WORD_H_

#include <string>
#include <memory>
#include <utility>

#include "src/operators/operator.h"
#include "modsecurity/rule_message.h"

namespace modsecurity {
namespace operators {

class ContainsWord : public Operator {
 public:
    /** @ingroup ModSecurity_Operator */
    explicit ContainsWord(std::unique_ptr<RunTimeString> param)
        : Operator("ContainsWord", std::move(param)) { }

    bool evaluate(Transaction *transaction, RuleWithActions *rule,
        const std::string &str,
        RuleMessage *ruleMessage) override;

 private:
    static bool acceptableChar(const std::string& a, size_t pos);
};

}  // namespace operators
}  // namespace modsecurity


#endif  // SRC_OPERATORS_CONTAINS_WORD_H_
