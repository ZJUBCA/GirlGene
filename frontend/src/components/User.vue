<template>
  <div class="user" >
    <div class="user-info">
      <el-row>
        <el-col :span="18">
          <el-row gutter="50px">
            <el-col :span="12" style="text-align: left;">Account</el-col>
            <el-col :span="12" style="text-align: right;">{{this.$store.state.account}}</el-col>
          </el-row>
          <el-row gutter="50px">
            <el-col :span="12" style="text-align: left;">Amount</el-col>
            <el-col :span="12" style="text-align: right;">{{this.$store.state.amount}}</el-col>
          </el-row>
          <br/>
          <el-row gutter="50px">
            <el-col :span="12" ><el-button @click="signOut()">Sign Out</el-button></el-col>
            <el-col :span="12" ><el-button type="primary" @click="addAssets()">Add Assets</el-button></el-col>
          </el-row>
        </el-col>
        <el-col :span="6">
          <img width="60%" src="../assets/head1.jpg">
        </el-col>
      </el-row>
    </div>
    <div class="user-market">
      <h3>Owned</h3>
      <el-row :gutter="50" v-for="i in 1" style="margin-bottom:30px;">
        <el-col :span="6" v-for="card in cards">
          <div class="grid-content bg-purple card" @click="toCard()">
            <div class="sale-tag"><span v-if="true">For sale </span>0.01 eos</div>
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
  </div>
</template>

<script>
  import ElButton from "../../node_modules/element-ui/packages/button/src/button.vue";
  import axios from 'axios'
  import ElRow from "element-ui/packages/row/src/row";
  export default {
    components: {
      ElRow,
      ElButton},
    name: 'User',
    data(){
      return {
        account:"girlmakegene",
        amount:"10",
        name:"Sakura",
        cardId:"a32f16bc",
        imgUrl:require("../assets/fakegirl.jpg"),
        cards:[]
      }
    },
    created(){
      axios.post(
        '/api/eos/amount',
        {
          account:this.$store.state.account
        }
      ).then((result)=>{
        this.$store.state.amount=result.data.amount;
        this.cards=this.$store.state.cards;
      })
    },
    methods:{
      toCard(){
        this.$store.state.operate=1;
        this.$router.push({path:'/card',query:{id:this.cardId}})
      },
      signOut(){
        this.$store.state.login=false;
        this.$store.state.account=null;
        this.$store.state.passwd=null;
        this.$store.state.amount=null;
        this.$store.state.operate=0;
        this.$router.push({path:"/home"})
      },
      addAssets(){

      }
    }
  }
</script>

<style scoped>
  .user{
    width:80%;
    margin:0 auto;
  }

  .user-info{
    font-size: large;
    border-radius: 10px;
    background-color: #545c64;
    color: white;
    padding:20px 30px;
  }

  .user-market{
    margin-top: 20px;
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
