/*
 * Copyright 2010-2018 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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
#include <aws/core/Core_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/http/HttpResponse.h>
#include <aws/core/client/AWSError.h>
#include <aws/core/client/AWSClient.h>
#include <aws/core/monitoring/CoreMetrics.h>

namespace Aws
{
    namespace Monitoring
    {
        /**
         * Monitoring interface definition for SDK metrics collection.
         */
        class AWS_CORE_API MonitoringInterface
        {
        public:
            virtual ~MonitoringInterface() = default;

            /**
             * @brief This function lets you do preparation work when a http attempt(request) starts. It returns a pointer to an implementation defined context which will be 
             * passed down with the other facilities that completes the request's lifetime. This context can be used to track the lifetime of the request and record metrics 
             * specific to this particular request. You are responsible for deleteing the context during your OnFinish call.
             * @param serviceName, the service client who initiates this http attempt. like "s3", "ec2", etc.
             * @param requestName, the operation or API name of this http attempt, like "GetObject" in s3.
             * @return implementation depends memory address of context.
             */    
            virtual void* OnRequestStarted(const Aws::String& serviceName, const Aws::String& requestName) const = 0;

            /**
             * @brief Once a Http attempt finished and received "Suceeded" response, this function will be called.
             * @param serviceName, the service client who initiate this http attempt. like "s3", "ec2", etc.
             * @param requestName, the operation or API name of this http attempt, like "GetObject" in s3.
             * @param outcome, the outcome of the http attempt, you can access httpResponse and original httpRequest from it.
             * @param metricsFromCore, metrics collected from core, such as detailed latencies during http connection.
             * @param context parameter pointed to the same place returned by OnRequestStarted() function.
             * @return void.
             */
            virtual void OnRequestSucceeded(const Aws::String& serviceName, const Aws::String& requestName, 
                    const Aws::Client::HttpResponseOutcome& outcome, const CoreMetricsCollection& metricsFromCore, void* context) const = 0;

            /**
             * @brief Once a Http request finished and received "Failed" response, this function will be called.
             * @param serviceName, the service client who initiate this http attempt. like "s3", "ec2", etc.
             * @param requestName, the operation or API name of this http attempt, like "GetObject" in s3.
             * @param outcome, the outcome of the http attempt, you can access httpResponse and original httpRequest from it.
             * @param metricsFromCore, metrics collected from core, such as detailed latencies during http connection.
             * @param context parameter pointed to the same place returned by OnRequestStarted() function.
             * @return void.
             */
            virtual void OnRequestFailed(const Aws::String& serviceName, const Aws::String& requestName, 
                    const Aws::Client::HttpResponseOutcome& outcome, const CoreMetricsCollection& metricsFromCore, void* context) const = 0;

            /**
             * @brief Once an API call retried the attempt and send the request again, this function will be called.
             * @param serviceName, the service client who initiate this http attempt. like "s3", "ec2", etc.
             * @param requestName, the operation or API name of this http attempt, like "GetObject" in s3.
             * @param context parameter pointed to the same place returned by OnRequestStarted() function.
             * @return void.
             */
            virtual void OnRequestRetry(const Aws::String& serviceName, const Aws::String& requestName, void* context) const = 0;

            /**
             * @brief This function will always be called by the SDK to signal the implementer that this request is done. The implementer can safely delete the context.
             * @param serviceName, the service client who initiate this http attempt. like "s3", "ec2", etc.
             * @param requestName, the operation or API name of this http attempt, like "GetObject" in s3.
             * @param context parameter pointed to the same place returned by OnRequestStarted() function.
             * @return void.
             */
            virtual void OnFinish(const Aws::String& serviceName, const Aws::String& requestName, void* context) const = 0;
        };
    } // namespace Monitoring
} // namepsace Aws