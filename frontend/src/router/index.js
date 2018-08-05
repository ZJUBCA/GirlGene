import Vue from 'vue'
import Router from 'vue-router'
import Home from '@/components/Home'
import Market from '@/components/Market'
import Factory from '@/components/Factory'
import User from '@/components/User'
import Card from '@/components/Card'

Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/',
      name: 'Home',
      component: Home
    },
    {
      path: '/home',
      name: 'Home',
      component: Home
    },
    {
      path:'/market',
      name:"Market",
      component:Market
    },
    {
      path:'/factory',
      name:'Factory',
      component:Factory
    },
    {
      path:'/user',
      name:'User',
      component:User
    },
    {
      path:'/card',
      name:'Card',
      component:Card
    }

  ]
})
