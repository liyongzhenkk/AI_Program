#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctime>
#include<stdint.h>
#include<stdbool.h>
#include<stddef.h>
#include<stdarg.h>
#include<time.h>
#include<sys/time.h>
#include<sys/types.h>
#include<sys/stat.h>

namespace ai_chat_sdk  {
    struct message {
        std::string _content;
        std::string _role;
        std::string _messageId;
        std::time_t _timestamp;
        message(const std::string& content, const std::string& role, const std::string& messageId, const std::time_t& timestamp)
         : _content(content), _role(role) {}
    };

    struct config {
        std::string _modelName; //模型名称
        double _temperature = 0.7; //温度
        int _maxTokens = 2048; //最大令牌数
    
    };

    //通过API 访问
    struct api_config : public config {
        std::string _apiKey;
    //通过ollama 访问
    struct ollama_config : public config {
    };

    struct ModelInfo{ 
        std::string _modelName; //模型名称
        std::string _modelDescription; //模型描述
        std::string _modelProvider; //模型提供者
        std::string _modelUrl; //模型URL
        std::string _endpoint; //基础URL
        std::bool _isAvailable = false; 
        
        ModelInfo(const std::string& modelName = "", const std::string& modelDescription = "", const std::string& modelProvider = "", const std::string& modelUrl = "", const std::string& endpoint = "", const bool& isAvailable = false)
         : _modelName(modelName), _modelDescription(modelDescription), _modelProvider(modelProvider), _modelUrl(modelUrl), _endpoint(endpoint), _isAvailable(isAvailable) {}
        
    }

    //会话信息
    struct sessionInfo {
        std::string _sessionId; //会话ID
        std::string _sessionName; //会话名称
        std::vector<message> _messages; //会话消息
        std::time_t _createTime; //会话创建时间
        std::time_t _updateTime;//会话更新时间
        
        sessionInfo(std::string sessionName = "")
         : _sessionName(sessionName) {}
    };
    
}//end  ai_chat_sdk