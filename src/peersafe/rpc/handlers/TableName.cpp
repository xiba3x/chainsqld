//------------------------------------------------------------------------------
/*
    This file is part of chainsqld: https://github.com/chainsql/chainsqld
    Copyright (c) 2016-2018 Peersafe Technology Co., Ltd.

	chainsqld is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
 
	chainsqld is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	You should have received a copy of the GNU General Public License
	along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
*/
//==============================================================================

#include <ripple/json/json_value.h>
#include <ripple/net/RPCErr.h>
#include <ripple/protocol/JsonFields.h>
#include <ripple/rpc/Context.h>
#include <ripple/rpc/handlers/Handlers.h>
#include <peersafe/rpc/impl/TableAssistant.h>
#include <ripple/rpc/impl/RPCHelpers.h>

namespace ripple {
Json::Value doGetDBName(RPC::Context&  context)
{
	Json::Value ret(Json::objectValue);
	Json::Value& tx_json(context.params);

	if (tx_json["account"].asString().empty() || tx_json["tablename"].asString().empty())
	{
		ret[jss::status] = "error";
		ret[jss::error_message] = "account or tablename is empty";
		return ret;
	}

    auto tableNameStr = tx_json["tablename"].asString();
	auto accountIdStr = tx_json["account"].asString();

	return context.app.getTableAssistant().getDBName(accountIdStr, tableNameStr);
}

} // ripple
