# Synchronized-Zero-Latency-Engine
一个简单的调度


## SZE_NEXT#5.0的配置写法

```json
{
    "Name":{
        "name": "8100_MAX",
        "lv": "5.0",
        "Out": "ShenEternity"
    },

    "Log":{
        "Debug":false
    },

    "SetConfig":{
        "SetGover":true,
        "CpuSet":true,
        "SetGoverConfig":true,
        "OifaceAndJoyose":true,
        "Uclmap":true
    },

    "Policy":{
        "policy1":"0",
        "policy2":"4",
        "policy3":"7"
    },


    "powersave":{
        "FREQ":{
            "MINCORE":2000000,
            "MIDCORE":2000000,
            "BIGCORE":2000000
        },
        "Governor":{
            "MINCORE":"sugov_ext",
            "MIDCORE":"sugov_ext",
            "BIGCORE":"sugov_ext"
        },
        "GoverConfig":{
            "MINCORE":{
                "Path1":"up_rate_limit_us",
                "Config1":1800,
                "Path2":"target_loads",
                "Config2":50,
                "Path3":"down_rate_limit_us",
                "Config3":1400
            },
            "MIDCORE":{
                "Path1":"up_rate_limit_us",
                "Config1":2000,
                "Path2":"target_loads",
                "Config2":55,
                "Path3":"down_rate_limit_us",
                "Config3":1400
            },
            "BIGCORE":{
                "Path1":"up_rate_limit_us",
                "Config1":2400,
                "Path2":"targe_loads",
                "Config2":50,
                "Path3":"down_rate_limit_us",
                "Config3":1400
            }
        },
        "CPU_UCLAMP":{
            "Background_cpu_uclamp_max":20,
            "Background_cpu_uclamp_min":0,
            "Top_app_cpu_uclamp_max":50,
            "Top_app_cpu_uclamp_min":0,
            "System-Background_cpu_uclamp_max":30,
            "System-Background_cpu_uclamp_min":0,
            "System_cpu_uclamp_max":40,
            "System_cpu_uclamp_min":0,
            "Foreground_cpu_uclamp_max":30,
            "Foreground_cpu_uclamp_min":0
        },
        "CPUSET":{
            "Background":"0-3",
            "Top_app":"0-7",
            "System-Background":"0-3",
            "Foreground":"0-6"
        },
        "EAS":{
            "EAS_Enable":true,
            "Feas_Enable":true
        },
        "CFS":{
            "Sched_wakeup_granularity_ns":5000000,
            "Sched_migration_cost_ns":2000000
        },
        "SYS":{
            "ConfigPath":{
                "path1":"/sys/devices/system/cpu/cpuidle/current_governor"
            },
            "Config":{
                "config1":"teo"
            }
        }

    },

    "balance":{
        "FREQ":{
            "MINCORE":2000000,
            "MIDCORE":2200000,
            "BIGCORE":2200000
        },
        "Governor":{
            "MINCORE":"sugov_ext",
            "MIDCORE":"sugov_ext",
            "BIGCORE":"sugov_ext"
        },
        "GoverConfig":{
            "MINCORE":{
                "Path1":"up_rate_limit_us",
                "Config1":1500,
                "Path2":"target_loads",
                "Config2":70,
                "Path3":"down_rate_limit_us",
                "Config3":1200
            },
            "MIDCORE":{
                "Path1":"up_rate_limit_us",
                "Config1":1500,
                "Path2":"target_loads",
                "Config2":75,
                "Path3":"down_rate_limit_us",
                "Config3":1200
            },
            "BIGCORE":{
                "Path1":"up_rate_limit_us",
                "Config1":1600,
                "Path2":"target_loads",
                "Config2":75,
                "Path3":"down_rate_limit_us",
                "Config3":1200
            }
        },
        "CPU_UCLAMP":{
            "Background_cpu_uclamp_max":70,
            "Background_cpu_uclamp_min":0,
            "Top_app_cpu_uclamp_max":70,
            "Top_app_cpu_uclamp_min":0,
            "System-Background_cpu_uclamp_max":70,
            "System-Background_cpu_uclamp_min":0,
            "System_cpu_uclamp_max":70,
            "System_cpu_uclamp_min":0,
            "Foreground_cpu_uclamp_max":70,
            "Foreground_cpu_uclamp_min":0
        },
        "CPUSET":{
            "Background":"0-3",
            "Top_app":"0-7",
            "System-Background":"0-3",
            "Foreground":"0-6"
        },
        "EAS":{
            "EAS_Enable":true,
            "Feas_Enable":true
        },
        "CFS":{
            "Sched_wakeup_granularity_ns":5000000,
            "Sched_migration_cost_ns":2000000
        },
        "SYS":{
            "ConfigPath":{
                "path1":"/sys/devices/system/cpu/cpuidle/current_governor"
            },
            "Config":{
                "config1":"teo"
            }
        }
    },


    "performance":{
        "FREQ":{
            "MINCORE":2000000,
            "MIDCORE":2400000,
            "BIGCORE":2400000
        },
        "Governor":{
            "MINCORE":"sugov_ext",
            "MIDCORE":"sugov_ext",
            "BIGCORE":"sugov_ext"
        },
        "GoverConfig":{
            "MINCORE":{
                "Path1":"up_rate_limit_us",
                "Config1":1000,
                "Path2":"target_loads",
                "Config2":75,
                "Path3":"down_rate_limit_us",
                "Config3":1100
            },
            "MIDCORE":{
                "Path1":"up_rate_limit_us",
                "Config1":1000,
                "Path2":"target_loads",
                "Config2":70,
                "Path3":"down_rate_limit_us",
                "Config3":1100
            },
            "BIGCORE":{
                "Path1":"up_rate_limit_us",
                "Config1":1000,
                "Path2":"target_loads",
                "Config2":70,
                "Path3":"down_rate_limit_us",
                "Config3":1100
            }
        },
        "CPU_UCLAMP":{
            "Background_cpu_uclamp_max":50,
            "Background_cpu_uclamp_min":0,
            "Top_app_cpu_uclamp_max":100,
            "Top_app_cpu_uclamp_min":0,
            "System-Background_cpu_uclamp_max":60,
            "System-Background_cpu_uclamp_min":0,
            "System_cpu_uclamp_max":70,
            "System_cpu_uclamp_min":0,
            "Foreground_cpu_uclamp_max":80,
            "Foreground_cpu_uclamp_min":0
        },
        "CPUSET":{
            "Background":"0-2",
            "Top_app":"0-7",
            "System-Background":"0-3",
            "Foreground":"0-5"
        },
        "EAS":{
            "EAS_Enable":false,
            "Feas_Enable":true
        },
        "CFS":{
            "Sched_wakeup_granularity_ns":2000000,
            "Sched_migration_cost_ns":800000
        },
        "SYS":{
            "ConfigPath":{
                "path1":"/sys/devices/system/cpu/cpuidle/current_governor"
            },
            "Config":{
                "config1":"teo"
            }
        }
    },


    "fast":{
        "FREQ":{
            "MINCORE":2000000,
            "MIDCORE":2850000,
            "BIGCORE":2850000
        },
        "Governor":{
            "MINCORE":"sugov_ext",
            "MIDCORE":"sugov_ext",
            "BIGCORE":"sugov_ext"
        },
        "GoverConfig":{
            "MINCORE":{
                "Path1":"up_rate_limit_us",
                "Config1":1100,
                "Path2":"target_loads",
                "Config2":80,
                "Path3":"down_rate_limit_us",
                "Config3":1200
            },
            "MIDCORE":{
                "Path1":"up_rate_limit_us",
                "Config1":1100,
                "Path2":"target_loads",
                "Config2":75,
                "Path3":"down_rate_limit_us",
                "Config3":1200
            },
            "BIGCORE":{
                "Path1":"up_rate_limit_us",
                "Config1":1100,
                "Path2":"target_loads",
                "Config2":80,
                "Path3":"down_rate_limit_us",
                "Config3":1000
            }
        },
       "CPU_UCLAMP":{
            "Background_cpu_uclamp_max":40,
            "Background_cpu_uclamp_min":0,
            "Top_app_cpu_uclamp_max":100,
            "Top_app_cpu_uclamp_min":0,
            "System-Background_cpu_uclamp_max":50,
            "System-Background_cpu_uclamp_min":0,
            "System_cpu_uclamp_max":60,
            "System_cpu_uclamp_min":0,
            "Foreground_cpu_uclamp_max":70,
            "Foreground_cpu_uclamp_min":0
        },
        "CPUSET":{
            "Background":"0-1",
            "Top_app":"0-7",
            "System-Background":"0-2",
            "Foreground":"0-5"
        },
        "EAS":{
            "EAS_Enable":false,
            
        },
        "CFS":{
            "Sched_wakeup_granularity_ns":1000000,
            "Sched_migration_cost_ns":500000
        },
        "SYS":{
            "ConfigPath":{
                "path1":"/sys/devices/system/cpu/cpuidle/current_governor"
            },
            "Config":{
                "config1":"teo"
            }
        }
    }
}
```

### 第一块（Name）：
    "Name":{
        "name": "8100_MAX",   <---- 配置的名字
        "lv": "5.0",          <---- 配置的版本   <---除了版本，其他都可以随便改
        "Out": "ShenEternity" <---- 配在的作者
    },


### 第二块（SetConfig）
    "SetConfig":{
        "SetGover":true,       <---- 自定义调速器开关  true为开   false为关
        "SetGoverConfig":true  <---- 自定义调速器参数开关  true为开   false为关    <----   只能填true或false
        "OifaceAndJoyoset":true<---- 屏蔽官调
    },


### 第三块（Policy）
    "Policy":{
        "policy1":"0",         <----  这里没什么可介绍的
        "policy2":"4",          /sys/devices/system/cpu/cpufreq/    用mt管理其器打开这个目录  你会发现有两个或两个以上的文件夹
        "policy3":"7"           将其中以   Policy + 数字命名的文件夹的数字填进去即可    如果你有两个就把配置里 的policy3给删了
    },                          如果有4个   就加一行  加一个policy4

### 第四块（模式）
    调度分为4个模式，这里以powersave（省电）模式为例


    "powersave":{
        "FREQ":{                        <----  FREQ字段   频率
            "MINCORE":2000000,          <----  小核最高频率
            "MIDCORE":2000000,          <----  中核最高频率         <----   如果你的Policy只有2个请将后面的删掉
            "BIGCORE":2000000,          <----  大核最高频率         <----   如果你的Policy只有3个请将后面的删掉
            "MAXCORE":2000000           <----  超大核最高频率
        },
        "Governor":{                    <----  Governor字段   调速器
            "MINCORE":"sugov_ext",      <----  小核调速器
            "MIDCORE":"sugov_ext",      <----  中核调速器         <----   如果你的Policy只有2个请将后面的删掉
            "BIGCORE":"sugov_ext",      <----  大核调速器         <----   如果你的Policy只有3个请将后面的删掉
            "MAXCORE":"sugov_ext"       <----  超大核调速器
        },
        "GoverConfig":{                         <----  GoverConfig字段   调速器参数    月月哟哟有有有的有的调速器有参数，有的没有，没有可直接删掉，比如我的大核，也就是 BIGCORE 用的是 performance 调速器， 这个调速器在我这没有参数，所以，可以把 BIGCORE 里面的全部删掉。  注意，调速器参数超过8个就不行了现在只支持8个。
            "MINCORE":{
                "Path1":"up_rate_limit_us",     <---- 调速器参数名  可以在  /sys/devices/system/cpu/cpufreq/Policy + 数字 + 调速器名  里面找到   例如：/sys/devices/system/cpu/cpufreq/Policy0/sugov_ext/
                "Config1":1000,                 <---- 调速器参数   可以在  /sys/devices/system/cpu/cpufreq/Policy + 数字 + 调速器名 + 参数名  里面看到，自行上网搜索各个参数的作用即可
                "Path2":"target_loads",         <---- 后面的以此类推
                "Config2":95,
                "Path3":"down_rate_limit_us",
                "Config3":700
            },
            "MIDCORE":{
                "Path1":"up_rate_limit_us",
                "Config1":1000,
                "Path2":"target_loads",
                "Config2":95,
                "Path3":"down_rate_limit_us",
                "Config3":700
            },                                          <----   如果你的Policy只有2个请将后面的删掉
            "BIGCORE":{
                "Path1":"up_rate_limit_us",
                "Config1":1000,
                "Path2":"targe_loads",
                "Config2":100,
                "Path3":"down_rate_limit_us",
                "Config3":700
            },                                          <----   如果你的Policy只有3个请将后面的删掉
            "MAXCORE":{
                "Path1":"up_rate_limit_us",
                "Config1":1000,
                "Path2":"targe_loads",
                "Config2":100,
                "Path3":"down_rate_limit_us",
                "Config3":700
            }
        },
        "CPU_UCLAMP":{                                      <----  CPU_UCLAMP字段
            "Background_cpu_uclamp_max":80,
            "Background_cpu_uclamp_min":0,
            "Top_app_cpu_uclamp_max":80,
            "Top_app_cpu_uclamp_min":0,
            "System-Background_cpu_uclamp_max":80,
            "System-Background_cpu_uclamp_min":0,           <----  微调  （这个我不知道怎么说，可以问ai）
            "System_cpu_uclamp_max":80,
            "System_cpu_uclamp_min":0,
            "Foreground_cpu_uclamp_max":80,
            "Foreground_cpu_uclamp_min":0
        },
        "CPUSET":{                                          <----  CPUSET字段
            "Background":"0-3",                                 <----  后台使用的cpu核心数
            "Top_app":"0-7",                                    <----  顶层使用的cpu核心数
            "System-Background":"0-3",                          <----  系统后台使用的cpu核心数
            "Foreground":"0-6"                                  <----  前台使用的cpu核心数
        }，
        "EAS":{                                                 <----  EAS字段
            "EAS_Enable":true,                                  <---- 开关，打游戏建议关
            "Feas_Enable":true                                  <---- 小米Feas 开关
        },
        "CFS":{
            "Sched_wakeup_granularity_ns":5000000,              <---- 唤醒抢占
            "Sched_migration_cost_ns":2000000                   <---- 进程迁移      <---- 两个都是越高越省电，但是太高也不好
        },
        "SYS":{                                                                     <---- SYS字段 （说是sys，但是只要 selinux允许，想改哪里都行）【如果你不用的话，就把path1,config1删掉，其他的不要删】
            "ConfigPath":{
                "path1":"/sys/devices/system/cpu/cpuidle/current_governor"          <---- 想要修改的文件路径
            },
            "Config":{
                "config1":"teo"                                                     <---- 想改的值（string类型，支持字符串，说白了 ，啥都能改）
            }
        }

    },
### Debug (找问题用的，一般不开)
    "Log":{
        "Debug":false
    },

