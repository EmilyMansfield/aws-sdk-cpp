﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#pragma once
#include <aws/robomaker/RoboMaker_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/robomaker/model/Fleet.h>
#include <utility>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils
namespace RoboMaker
{
namespace Model
{
  class AWS_ROBOMAKER_API ListFleetsResult
  {
  public:
    ListFleetsResult();
    ListFleetsResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    ListFleetsResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    /**
     * <p>A list of fleet details meeting the request criteria.</p>
     */
    inline const Aws::Vector<Fleet>& GetFleetDetails() const{ return m_fleetDetails; }

    /**
     * <p>A list of fleet details meeting the request criteria.</p>
     */
    inline void SetFleetDetails(const Aws::Vector<Fleet>& value) { m_fleetDetails = value; }

    /**
     * <p>A list of fleet details meeting the request criteria.</p>
     */
    inline void SetFleetDetails(Aws::Vector<Fleet>&& value) { m_fleetDetails = std::move(value); }

    /**
     * <p>A list of fleet details meeting the request criteria.</p>
     */
    inline ListFleetsResult& WithFleetDetails(const Aws::Vector<Fleet>& value) { SetFleetDetails(value); return *this;}

    /**
     * <p>A list of fleet details meeting the request criteria.</p>
     */
    inline ListFleetsResult& WithFleetDetails(Aws::Vector<Fleet>&& value) { SetFleetDetails(std::move(value)); return *this;}

    /**
     * <p>A list of fleet details meeting the request criteria.</p>
     */
    inline ListFleetsResult& AddFleetDetails(const Fleet& value) { m_fleetDetails.push_back(value); return *this; }

    /**
     * <p>A list of fleet details meeting the request criteria.</p>
     */
    inline ListFleetsResult& AddFleetDetails(Fleet&& value) { m_fleetDetails.push_back(std::move(value)); return *this; }


    /**
     * <p>The <code>nextToken</code> value to include in a future
     * <code>ListDeploymentJobs</code> request. When the results of a
     * <code>ListFleets</code> request exceed <code>maxResults</code>, this value can
     * be used to retrieve the next page of results. This value is <code>null</code>
     * when there are no more results to return. </p>
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * <p>The <code>nextToken</code> value to include in a future
     * <code>ListDeploymentJobs</code> request. When the results of a
     * <code>ListFleets</code> request exceed <code>maxResults</code>, this value can
     * be used to retrieve the next page of results. This value is <code>null</code>
     * when there are no more results to return. </p>
     */
    inline void SetNextToken(const Aws::String& value) { m_nextToken = value; }

    /**
     * <p>The <code>nextToken</code> value to include in a future
     * <code>ListDeploymentJobs</code> request. When the results of a
     * <code>ListFleets</code> request exceed <code>maxResults</code>, this value can
     * be used to retrieve the next page of results. This value is <code>null</code>
     * when there are no more results to return. </p>
     */
    inline void SetNextToken(Aws::String&& value) { m_nextToken = std::move(value); }

    /**
     * <p>The <code>nextToken</code> value to include in a future
     * <code>ListDeploymentJobs</code> request. When the results of a
     * <code>ListFleets</code> request exceed <code>maxResults</code>, this value can
     * be used to retrieve the next page of results. This value is <code>null</code>
     * when there are no more results to return. </p>
     */
    inline void SetNextToken(const char* value) { m_nextToken.assign(value); }

    /**
     * <p>The <code>nextToken</code> value to include in a future
     * <code>ListDeploymentJobs</code> request. When the results of a
     * <code>ListFleets</code> request exceed <code>maxResults</code>, this value can
     * be used to retrieve the next page of results. This value is <code>null</code>
     * when there are no more results to return. </p>
     */
    inline ListFleetsResult& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * <p>The <code>nextToken</code> value to include in a future
     * <code>ListDeploymentJobs</code> request. When the results of a
     * <code>ListFleets</code> request exceed <code>maxResults</code>, this value can
     * be used to retrieve the next page of results. This value is <code>null</code>
     * when there are no more results to return. </p>
     */
    inline ListFleetsResult& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}

    /**
     * <p>The <code>nextToken</code> value to include in a future
     * <code>ListDeploymentJobs</code> request. When the results of a
     * <code>ListFleets</code> request exceed <code>maxResults</code>, this value can
     * be used to retrieve the next page of results. This value is <code>null</code>
     * when there are no more results to return. </p>
     */
    inline ListFleetsResult& WithNextToken(const char* value) { SetNextToken(value); return *this;}

  private:

    Aws::Vector<Fleet> m_fleetDetails;

    Aws::String m_nextToken;
  };

} // namespace Model
} // namespace RoboMaker
} // namespace Aws
