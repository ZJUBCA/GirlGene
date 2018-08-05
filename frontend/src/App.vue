<template>
  <div id="app">
    <el-container>
   <el-header style="padding:0;">
     <el-menu
       :default-active="activeIndex"
       class="el-menu-demo"
       router="true"
       mode="horizontal">
       <el-menu-item index="home" style="text-decoration: none"><img style="width:72px;height:51px" src="./assets/logo.png"/></el-menu-item>
       <el-menu-item index="factory" style="float: right">Factory</el-menu-item>
       <el-menu-item index="market" style="float: right">Market</el-menu-item>
       <el-menu-item index="home" style="float: right" v-if="this.$store.state.login==false" @click="toSignIn()">Sign</el-menu-item>
       <el-menu-item index="user" style="float: right" v-if="this.$store.state.login==true"><img width="50px" src="./assets/head1.jpg"></el-menu-item>
     </el-menu>
   </el-header>
      <el-main>
          <router-view/>
      </el-main>
    </el-container>
    <el-dialog title="Sign In" :visible.sync="dialogFormVisible">
      <el-form :model="form">
        <el-form-item label="Account" :label-width="formLabelWidth">
          <el-input v-model="form.account" auto-complete="off"></el-input>
        </el-form-item>
      </el-form>
      <div slot="footer" class="dialog-footer">
        <el-button @click="dialogFormVisible = false">取 消</el-button>
        <el-button type="primary" @click="signIn()">确 定</el-button>
      </div>
    </el-dialog>

  </div>
</template>

<script>
import ElHeader from "../node_modules/element-ui/packages/header/src/main.vue";
import ElContainer from "../node_modules/element-ui/packages/container/src/main.vue";
import axios from 'axios'
export default {
  components: {
    ElContainer,
    ElHeader
  },
  name: 'App',
  data(){
    return {
      activeIndex:'home',
      form:{
        account:null
      },
      dialogFormVisible:false
    }
  },
  methods:{
    toSignIn(){
      this.dialogFormVisible=true;
    },
    signIn(){
      axios.post("/api/eos/login",
        {
          account:this.form.account
        }).then(result=>{
        this.dialogFormVisible=false;
        this.$store.state.login=true;
        this.$store.state.account=this.form.account;
        this.$router.push({path:"/user"})
      }).catch((err)=>{
        console.log(err)
        this.dialogFormVisible=false;
        this.$alert('账号不存在', '提示', {
          confirmButtonText: '确定',
          callback: action => {
            this.$message({
              type: 'info',
              message: `action: ${ action }`
            });
          }
        });
      })
    }
  }
}
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}
  a{
    text-decoration: none;
  }
</style>
