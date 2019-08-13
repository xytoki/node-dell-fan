var addon = require('bindings')('addon.node')
var Path=require("path");
module.exports={
	load:function(path){
		addon.load(path||(__dirname+Path.sep+'bzh_dell_smm_io_x64.sys'));
	},
	unload:addon.unload,
	command:addon.command,
	setFanSpeed:addon.setFanSpeed,
	setFull(fan){
		return this.setFanSpeed(fan||this.FAN1,this.FULL);
	},
	setSlow(fan){
		return this.setFanSpeed(fan||this.FAN1,this.SLOW);
	},
	setStop(fan){
		return this.setFanSpeed(fan||this.FAN1,this.STOP);
	},
	getRPM(fan){
		return this.command(this.GET_RPM,fan||this.FAN1);
	},
	getTemp(sensor){
		return this.command(this.SENSOR,sensor||this.FAN1);
	},
	//commands
	DISABLE_CTL1 :0x30a3,
	ENABLE_CTL1  :0x31a3,
	DISABLE_CTL2 :0x34a3,
	ENABLE_CTL2  :0x35a3,
	GET_LV       :0x00a3,
	SET_LV       :0x01a3,
	GET_RPM      :0x02a3,
	//speed
	STOP         :0x0000,
	SLOW         :0x0001,
	FULL         :0x0002,
	//fanid
	FAN1         :0,
	FAN2         :1,
	NO_ARG       :0x0,
	//sensor
	SENSOR		 :0x10a3
};