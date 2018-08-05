<template>
  <div class="market" >

    <h3>For Sale</h3>
    <el-row :gutter="50" v-for="i in 4" style="margin-bottom:30px;">
      <el-col :span="6" v-for="i in 4">
        <div class="grid-content bg-purple card" @click="toCard()">
          <div class="sale-tag">For sale : 0.01 eos</div>
          <div class="card-img"><img v-bind:src="imgUrl"/></div>
          <div class="card-info">
            <el-row gutter="50px">
              <el-col :span="12" style="text-align: left;">{{name}}</el-col>
              <el-col :span="12" style="text-align: right;">#{{cardId}}</el-col>
            </el-row>
          </div>
        </div>
      </el-col>
    </el-row>

  </div>
</template>

<script>
  export default {
    name: 'Market',
    data(){
      return {
        name:"Sakura",
        cardId:"bc34a2ef",
        imgUrl:require("../assets/fakegirl.jpg")
      }
    },
    methods:{
      toCard(){
        this.$store.state.operate=0;
        this.$router.push({path:'/card',query:{id:this.cardId}})
      }
    }
  }
</script>

<style scoped>
  .market{
    width:80%;
    margin:0 auto;
  }
  .card{
    border-radius: 10px;
    background-color:#ffe05b;
    overflow: hidden;
  }
  .sale-tag{
    height:20px;
    padding-top:5px;
    margin:0 auto;
    background-color: #545c64;
    color: white;
  }
  .card-info{
    height:30px;
    padding: 0 20px;
    font-size:20px;
    background-color: #545c64;
    color: white;
    font-family: "微软雅黑";

  }
</style>
